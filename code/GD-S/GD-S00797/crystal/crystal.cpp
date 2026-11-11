#include<bits/stdc++.h>
using namespace std;
const long long maxn=5e5+10;
unsigned long long n,m;
int a[maxn],vis[maxn];
vector<int> vistor;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(vis[a[i]]!=-1&&a[i]<=n){
			vistor.push_back(a[i]);
			vis[a[i]]=-1;
		}
	}
	long long x=a[n]-a[n-1];
	long long ans=1;
	long long l=1;
	if(vistor.size()==n){
		while(m){
			if(l>m){
				break;
			}
			m-=l;
			l++;
			ans++;
		}
	}
	else{
		while(m){
			if(l*x>m){
				break;
			}
			m-=l*x;
			ans++;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
