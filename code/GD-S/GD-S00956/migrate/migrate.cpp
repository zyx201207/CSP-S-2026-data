#include<bits/stdc++.h>
#define int long long
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define frep(i,s,t) for(int i=s;i>=t;i--)
#define rep1(i,s,t) for(int i=s;i<t;i++)
#define frep1(i,s,t) for(int i=s;i>t;i--)
#define set(ai,k) memset(ai,k,sizeof(ai))
#define srt(ai,n) sort(ai+1,ai+1+n)
#define csrt(ai,n,cmp) sort(ai+1,ai+1+n,cmp)
#define pb push_back
using namespace std;
const int N=2e6+5;
int c,T,ai[N],d,n,bi[N],k,in[N],out[N],cnt,di[N],ff[N],sm,ans,f[N];
void slv(){
	if(k==1)return;
	int t=1;
	cnt=0;sm=0;
	rep(i,1,k)ff[i]=0;
	rep(i,2,k){
		while(t<=i&&bi[i]-bi[t]>d)t++;
		ff[i]=t;
	}
//	rep(i,1,k)cout<<ff[i]<<" ";cout<<endl;
	if(c==11||c==12){
		f[1]=1;di[1]=0;
		rep(j,1+1,k){
			if(ff[j]<1)ff[j]=1;
			di[j]=di[ff[j]]+1;
		}
		rep(j,1+1,k){
			if(ff[j]+2<j){
				if(di[ff[j]]==di[ff[j]+1]&&di[ff[j]]==di[ff[j]+2]){f[j]=3;continue;}
			}
			if(ff[j]+1<j){
				if(di[ff[j]]==di[ff[j]+1])f[j]=f[ff[j]]+f[ff[j]+1];
				else f[j]=f[ff[j]];
			}
			else f[j]=f[ff[j]];
			if(f[j]==2)ans+=n-j+1;
		}
		return;
	}
	rep(i,1,k){
		f[i]=1;di[i]=0;
		rep(j,i+1,k){
			if(ff[j]<i)ff[j]=i;
			di[j]=di[ff[j]]+1;
		}
		rep(j,i+1,k){
			if(ff[j]+2<j){
				if(di[ff[j]]==di[ff[j]+1]&&di[ff[j]]==di[ff[j]+2]){f[j]=3;continue;}
			}
			if(ff[j]+1<j){
				if(di[ff[j]]==di[ff[j]+1])f[j]=f[ff[j]]+f[ff[j]+1];
				else f[j]=f[ff[j]];
			}
			else f[j]=f[ff[j]];
			if(f[j]==2)ans++;
		}
	//	cout<<"st "<<i<<endl;
	//	rep(j,i+1,k)cout<<f[j]<<" "<<di[j]<<" "<<ff[j]<<endl;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		rep(i,1,n){
			cin>>ai[i];
		}
		rep1(i,1,n){
			int j=i+1;
			while(j<=n&&ai[j]-ai[j-1]<=d)j++;
			j--;k=0;
			rep(l,i,j)bi[++k]=ai[l];
		//	cout<<i<<" "<<j<<endl;
			slv();
			i=j;
		}
		cout<<ans<<endl;
	}
}
