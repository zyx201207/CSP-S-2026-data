#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define R(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=2e6+5;
int c,T,n,l[N],f[N],g[N],ans[N],num[N];
long long d,x[N];
void solve_n2(){
	cin>>n>>d;F(i,1,n) cin>>x[i],l[i]=0;
	F(i,1,n)F(j,1,i)if(x[i]-x[j]<=d){l[i]=j;break;}
	long long ans=0;
	F(L,1,n){
		F(i,0,n) f[i]=g[i]=0;g[L]=1;
		F(r,L+1,n){
			if(!l[r]) break;
			int pos=max(l[r],L);f[r]=f[pos]+1;
			g[r]=g[pos];
			if(pos+1<r&&f[pos+1]==f[r]-1) g[r]+=g[pos+1];
			if(pos+2<r&&f[pos+2]==f[r]-1) g[r]+=g[pos+2]; 
			g[r]=min(g[r],3);
			ans+=(g[r]==2);
		}
	}cout<<ans<<'\n';
}void solve_dengcha(){
	cin>>n>>d;F(i,1,n) cin>>x[i],ans[i]=l[i]=f[i]=g[i]=0;long long gc=x[n]-x[n-1];g[1]=1;
	if(n==1||gc>d){cout<<"0\n";return;}
	int j=1;F(i,1,n){while(j<i&&x[i]-x[j]>d) j++;l[i]=j;}
	F(r,2,n){int p=l[r];f[r]=f[p]+1,g[r]=g[p];if(p+1<r&&f[p+1]==f[p]) g[r]+=g[p+1];if(p+2<r&&f[p+2]==f[p]) g[r]+=g[p+2];g[r]=min(g[r],3);}
	F(i,2,n) ans[i]=ans[i-1]*2-ans[i-2]+(g[i]==2);
	cout<<ans[n]<<'\n';
}void solve_mid(){
	cin>>n>>d;F(i,1,n) cin>>x[i],num[i]=l[i]=0;int mid=0;
	int j=1;F(i,1,n){while(j<i&&x[i]-x[j]>d) j++;l[i]=j;}
	R(i,n,1)if(x[i]-x[1]<=d&&x[n]-x[i]<=d){mid=i;break;}
	F(i,1,n)if(l[i]!=1) num[l[i]]++;
	cout<<num[mid-1]<<'\n';
}void solve(){
	if(c<=10) solve_n2();
	else if(c==11||c==12) solve_dengcha();
	else solve_mid();
}int main(){
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
