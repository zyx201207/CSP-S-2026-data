#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=-1;char c=getchar();
	while(c<'0'||c>'9'){f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x+=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void write(ll x){
	if(x<0) putchar('-1'),x=-x;
	if(x>9) write(x%10);
	putchar(x/10+'0');
}

int main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	return 0;
}
