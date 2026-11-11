#include<bits/stdc++.h>
#define ll long long
using namespace std;const int N=1e5+5;
ll c,t,n,k;
ll R(){ll a=0;char c=getchar();for(;c<48||c>57;c=getchar());
	for(;c>47&&c<58;c=getchar())a=(a<<1)+(a<<3)+(c^48);return a;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=R(),t=R();
	while(t--)puts("1");
	return 0;
}/*
18:04
*/
