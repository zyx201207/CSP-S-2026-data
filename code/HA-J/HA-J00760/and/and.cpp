#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read(){ int x=0,f=1;char ch=getchar();while(!isdigit(ch)){ if(ch=='-'){ f=-1; }ch=getchar(); }while(isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48);ch=getchar(); }return x*f; }
inline void write(int x){ if(x<0){ putchar('-');x=-x; }int cnt=0;char c[23];do{ c[++cnt]=x%10|48;x/=10; }while(x);while(cnt){ putchar(c[cnt--]); }putchar(' '); }
const int mod=998244353,N=200005;
int n,m,a[N];
vector<int>now[2];
signed main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;int r=0,ans=0;
	for(int i=1;i<=n;i++){ cin>>a[i];now[r].push_back(a[i]); }
	for(int i=30;i>=0;i--){
		int sum=0;
		for(int j=now[r].size()-1;j>=0;j--)sum+=((now[r][j]>>i)&1);
		if(sum>=m){
			ans|=(1<<i);
			for(int j=now[r].size()-1;j>=0;j--)if((now[r][j]>>i)&1)now[r^1].push_back(now[r][j]);
			now[r].clear();r^=1;
		}
	}
	cout<<ans;
	return 0;
}
