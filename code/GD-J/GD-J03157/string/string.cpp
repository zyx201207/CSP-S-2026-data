#include<bits/stdc++.h>
#define ll long long
#define ri register int
#define stg string
#define Cn const
#define ld long double
using namespace std;
int read() {
    int r=0,fl=1;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') fl=-fl;c=getchar();}
    while(c>='0'&&c<='9') {r=(r<<3)+(r<<1)+(c^48);c=getchar();}
    return r*fl;
}
int Max(int a,int b) {return a>b?a:b;}
int Min(int a,int b) {return a<b?a:b;}
Cn ld eps=1e-9;
Cn ll Inf=1e18;
Cn int N=2e5+5;
int n,a[N],l,r;
ll ans;
char c[N];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) {
		a[i]=read();cin>>c[i];
	}
	l=1,r=n;
	while(l<r) {
		ll mn=Min(a[l],a[r]);
		a[l]-=mn,a[r]-=mn;
		if(c[l]!=c[r]) ans+=mn;
		if(!a[l]) l++;
		if(!a[r]) r--;
	}
	cout<<ans;
	return 0;
}
