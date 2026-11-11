#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=2000050;
const ll ind=1e18;
ll read(){
	char ch=getchar();
	ll x=0,f=1;
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
void write(ll x){
	if(x<0) putchar('-');
	x=abs(x);
	if(x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
ll c,T,n,d;
ll x[5005],mp[5005][5005],dis[5005][5005],cnt[5005][5005]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	T=read();
	//cout<<inf<<endl;
	while(T--){
		cin>>n>>d;
		for(ll i=1;i<=n;++i) cin>>x[i],x[i]+=ind;
		for(ll i=1;i<=n;++i){
			for(ll j=1;j<i;++j){
				cnt[i][j]=0;
				dis[i][j]=inf;
				if(x[i]-x[j]<=d){
					dis[i][j]=1;
					cnt[i][j]=1;
				}
			}
		}
		for(ll i=1;i<=n;++i){
			for(ll j=1;j<i;++j){
				for(ll k=j+1;k<i;++k){
					if(dis[i][k]!=inf&&dis[k][j]!=inf){
						ll t=dis[i][k]+dis[k][j];
						if(t==dis[i][j]) cnt[i][j]+=cnt[i][k]*cnt[k][j];
						else if(t<dis[i][j]) dis[i][j]=t,cnt[i][j]=cnt[i][k]*cnt[k][j];
					}
				}
			}
		}
		ll ans=0;
		for(ll i=1;i<=n;++i){
			for(ll j=1;j<i;++j){
				//cout<<dis[i][j]<<" ";
				if(cnt[i][j]==2) ans++;
			}
			//cout<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
