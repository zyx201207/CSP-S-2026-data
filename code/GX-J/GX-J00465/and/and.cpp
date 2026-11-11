#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=2e5+5;
ll a[MAXN][35],c[MAXN],vis[MAXN];
int n,m;
int b[MAXN],ml=0;
void g2(ll x,ll id){
	int j=0;
	while(x!=0){
		a[id][j]=x%2;
		x=x/2;
		++j;
	}
	c[id]=j-1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		cin>>b[i];
		g2(b[i],i);
	}
	for(int i=1;i<=n;++i){
		if(ml<c[i]) ml=c[i];
		vis[i]=1;
	}
	ll ans=0;
	for(int	i=ml;i>=0;--i){
		int cnt=0;
		for(int j=1;j<=n;++j){
			if(a[j][i]==1&&vis[j]!=0){
				cnt++;
			}
			else{
				vis[j]=0;
			}
		}
		//cout<<i<<"  |"<<cnt<<endl;
		if(cnt>=m){
			ans+=(1<<i);
		}
	}
	cout<<ans<<endl;
	return 0;
}
