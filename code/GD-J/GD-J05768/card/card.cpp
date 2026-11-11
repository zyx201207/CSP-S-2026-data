#include<bits/stdc++.h>
#define Y(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
typedef long long ll;
using namespace std;
ll n,m,a[500005],v[300005];
inline ll r(){
	ll x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
int main(){
	Y("card");
	n=r(),m=r();
	for(int i=1;i<=n;i++)a[i]=r();
	for(int i=1;i<=m;i++)cout<<a[i]<<' ';
}
//Trick||Treat!
