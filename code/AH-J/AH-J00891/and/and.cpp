#include<iostream>
#include<cmath>
using namespace std;
const int N=2e5+9;
int n,m,cnt=0;
long long a[N];
bool vis[N]={0};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long maxn=-1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	int si=0;
	for(int i=30;i>=0;i--){
		if(((1<<i)-1)>=maxn) si=i-1;
	}
	for(int i=si;i>=0;i--){
		for(int j=0;j<n;j++){
			if(n-cnt==m) break;
			if(vis[j]) continue;
			int b=a[j]&(1<<i);
			if(b==0){
				vis[j]=1;
				cnt++;
			}
		}
	}
	long long ans=0;
	bool k=0;
	for(int i=0;i<n;i++){
		if(!vis[i]){
			if(!k) ans=a[i];
			else ans=ans&a[i];
		}
	}
	cout<<ans;
	return 0;
}
