#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxa,t;
bool vis[200005];
long long ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxa) maxa=a[i],t=i;
	}
	if(m==1){
		cout<<maxa;return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				long long x=a[i]&a[j];
				ans=max(ans,x);
			}
		}
		cout<<ans;return 0;
	}
	
	long long now=0;
	for(int i=1;i<=m;i++){
		if(i==1){
			ans=maxa,vis[t]=1;continue;
		}
		now=0;
		for(int j=1;j<=n;j++){
			if(vis[j]==0){
				long long x=ans&a[j];//cout<<x<<endl;
				if(x>now) now=x,t=j;
			}
		}
		vis[t]=1;
		ans=now;
//		cout<<t<<' '<<now<<endl;
	}
	cout<<ans;
	return 0;
}
