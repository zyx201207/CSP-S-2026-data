#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int const N=1e5+10;
inline int readInt(){
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
inline ll readll(){
	char c=getchar();ll x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-') f=-1ll;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10ll+c-'0';c=getchar();}
	return x*f;
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	return 0;
}

