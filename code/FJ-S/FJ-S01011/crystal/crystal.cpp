#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int read();
const int N=5e5+10;
int n,m,a[N],pre[N],ans;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int l=1,r=1;
	for(int l=1,r=1;l<=r && r<=n;r++) {
		while(l+1<=r && a[r]*(r-l)-(pre[r-1]-pre[l-1])>m) l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
int read() {
	int Ca=0;char Cr=' ';int Cf=1;
	while(Cr<'0' || Cr>'9') {Cr=getchar();if(Cr=='-') Cf=-1;}
	while(Cr>='0' && Cr<='9') {Ca=(Ca<<3)+(Ca<<1)+Cr-48,Cr=getchar();}
	return Ca*Cf;
}

