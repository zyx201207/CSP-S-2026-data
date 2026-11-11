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
Cn int N=2e5+5,LOG=29;
vector<int> v,nxt;
int n,a[N],m,ans;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) v.push_back(a[i]);
	for(int i=LOG;i>=0;i--) {
		int nw=(1<<i);
		nxt.clear();
		for(auto p:v) {
			if(p&nw) nxt.push_back(p);
		}
		if(nxt.size()>=m) {
			ans+=nw;
			v.clear();
			for(auto p:nxt) v.push_back(p);
		}
	}
	cout<<ans;
	return 0;
}
