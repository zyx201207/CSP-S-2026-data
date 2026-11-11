//GZ-J00350 贵阳市第三实验中学 郑思成
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f
#define INF 0x3f3f3f3f3f3f
using namespace std;
int n,m;
ll a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		ll maxx=-INF;
		for(int i=1;i<=n;i++){
			maxx=max(a[i],maxx);
		}
		cout<<maxx;
	}else if(m==2){
		ll maxx=-INF;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){continue;}
				maxx=max(a[i]&a[j],maxx);
			}
		}
		cout<<maxx;
	}else if(m==n){
		ll ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	return 0;
}

