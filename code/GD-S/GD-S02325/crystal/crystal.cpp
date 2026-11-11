#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+10;
int a[N];
long long cnt[N];
int c[N];//a[i]Óë´Óa[i+1] µÄ²î 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	sort(a+1,a+n+1);
	unique(a+1,a+n+1)-a-1;
	int minn=1e9;
	for(int i=1;i<n;i++){
		c[i]=a[i+1]-a[i];
	}
	long long maxn=0;
	for(int j=1;j<=n;j++){
		long long ans=1;
		for(int i=j;i<=n;i++){
			if(m==0) break;
			if(m-c[i]>=0){
				m-=c[i];
				ans++;
				c[i+1]=ans*c[i+1];
				
				if(cnt[a[i+1]]>1) ans+=cnt[a[i+1]]-1;
			}
			else if(i!=1&&m-c[i]/ans>=0){
				if(ans<cnt[a[i+1]]+1){
					ans=cnt[a[i+1]]+1;
					break;
				}
				else break;
			}
			else break;
		}
		maxn=max(ans,maxn);
	}
	
	cout<<maxn;
	return 0;
}
