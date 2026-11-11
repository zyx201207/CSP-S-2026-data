#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],vis[300010],ans[500010],b[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	ll l=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++){
		for(int j=1;j<=n;j++) b[j]=a[j];
		ll num=i;
		memset(vis,0x3f3f3f3f,sizeof vis);
		l=num;
		while(num<=n){
			ll x=a[num];
			if(vis[x]>300000){
				vis[x]=l;
			}
			else if(l>=vis[x]){
				l=vis[x];
			}else vis[x]=500010;
			b[l]=x;
			l++;num++;
		}
		l-=1,num-=1;
		for(int j=i;j<=l;j++){
			ans[b[j]]++;
		}
	}
	ans[a[n]]++;
for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
} 
