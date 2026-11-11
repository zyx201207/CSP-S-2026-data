#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read(){ int x=0,f=1;char ch=getchar();while(!isdigit(ch)){ if(ch=='-'){ f=-1; }ch=getchar(); }while(isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48);ch=getchar(); }return x*f; }
inline void write(int x){ if(x<0){ putchar('-');x=-x; }int cnt=0;char c[23];do{ c[++cnt]=x%10|48;x/=10; }while(x);while(cnt){ putchar(c[cnt--]); }putchar(' '); }
const int mod=998244353,N=500005;
int n,a[N],m,cnt[N],lst[N],bs[N];
signed main(){
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];lst[a[i]]=i;bs[i]=1;}
	for(int i=1;i<=n;i++){
		bs[lst[a[i]]+1]+=bs[i];
	}
	for(int i=1;i<=n;i++){
		cnt[a[i]]+=bs[i];
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}
