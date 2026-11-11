#include<bits/stdc++.h>
#define ll long long
#define lll __int128_t
using namespace std;
const int N=2e6+10; 
const ll w[4][3]={{1,1,1},{1,1,3},{1,3,3},{2,3,3}};
int n,ct;
ll d,r[N],x[N],f[N][4];
int R(int i){return (i>0)?r[i]:0;}

void solve(){
	cin>>n>>d;ct++;
	for(int i=1;i<=n;++i)r[i]=f[i][0]=f[i][1]=f[i][2]=f[i][3]=0;
	for(int i=1;i<=n;++i)cin>>x[i];
	for(int i=1,j=0;i<=n;++i){while(j+1<=n&&((lll)x[j+1]-(lll)x[i]<=d))++j;r[i]=j;}
	ll ans=0;for(int i=n;i;--i){
		int j=r[i];
		if(j>i)for(int s=0;s<4;++s){
			ll v=0;
			if(s<2)v=max(0,R(i-1)-max(i,R(i-2)));
			else if(s==3)v=j-max(i,R(i-1));
			ll a[3]={0,0,0};
			for(int k=0;k<3;++k){
				int t=j-k,z=0;
				if(t<=i)z=3;
				else {for(int h=0;h<3;++h)if(R(i-h)>=t){z+=w[s][h];}}
				a[k]=min(z,3);
			}
			if(a[0]<3){
				int q=a[0]==2?3:a[1]>1?2:a[2]>1?1:0;
				v+=f[j][q];
			}
			f[i][s]=v;
		}
		ans+=f[i][2];
	}
	cout<<ans<<"\n";
	return;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,T;cin>>c>>T;while(T--)solve(); 
	return 0;
}
