#include<bits/stdc++.h>
using namespace std;
#define ll long long

inline int read(){
	int a=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9'){
		a=(a<<3)+(a<<1)+(ch-'0');
		ch=getchar();
	}
	return a*f;
}
inline void write(int a){
	if (a<0){
		a=-a;
		putchar('-');
	}
	if (a>=10) write(a/10);
	putchar(a%10+'0');
}
const int N=5e5+100;
ll n,m,li[N],ans,s[N];
bool cmp(ll a,ll b){
	return a<b;
}
ll f(ll w){
	ll l=1,r=w-1,ans=0;
	while (l<r){
		ll mid=l+r>>1;
		if (s[w-1]-s[mid-1]+m>(w-mid)*li[w]){
			r=mid;
			ans=mid;
		}
		else l=mid+1;
	}
	return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for (int i=1;i<=n;i++){
		li[i]=read();
	}
	sort(li+1,li+1+n,cmp);
	for (int i=1;i<=n;i++){
		s[i]=s[i-1]+li[i];
	}
	for (int i=1;i<=n;i++){
		ans=max(ans,i-f(i)+1);
	}
	write(ans);putchar('\n');
	return 0;
}
/*
Oct31==Dec25?

5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
