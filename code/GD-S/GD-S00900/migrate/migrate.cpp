#include<bits/stdc++.h> 
#define int long long
#define mem(a) memset(a,0,sizeof(a))
#define size(s) ((int)(s.size()))

using namespace std;

bool ppp;

const int N=2e6+5;

long long n,d,a[N],fa[N],f[N][2][2],ans;

void clean(){
	for(int i=0;i<=n+2;i++) a[i]=fa[i]=0,mem(f[i]);
	n=d=ans=0;
}

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	int j=1;
	for(int i=1;i<=n;i++){
		while(j<n&&a[j+1]-a[i]<=d) j++;
		fa[i]=j;
	}
	for(int i=1;i<=n;i++){
		//f_1,0
		ans+=(fa[i]-max(fa[i-1],i))*f[i][1][0];
		//f_0,1
		if(i>1) ans+=(max(fa[i-1],i)-max(fa[i-2],i))*f[i][0][1];
		
		if(fa[i]==i) continue;
		int x=fa[i];
		f[x][0][1]++;
		if(i==1||fa[i-2]!=fa[i]){
			if(fa[i-1]==fa[i]){
				f[x][1][0]+=f[i][0][1];
			}
			else{
				f[x][1][0]+=f[i][1][0];
				f[x][0][!(fa[i-1]==x-1)]+=f[i][0][0]+f[i][0][1];
			}
		}
	}
	cout<<ans<<"\n";
}

bool qqq;

signed main(){
//	cerr<<((&ppp)-(&qqq))/1048576.0<<"\n";
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t>>t;
	while(t--) solve(),clean();
}
