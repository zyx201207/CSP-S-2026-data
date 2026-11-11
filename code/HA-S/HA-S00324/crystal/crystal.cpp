#include<bits/stdc++.h>
#define ll long long
#define int long long 
using namespace std;
inline ll read(){
	ll x=0; int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=500005;
int n,m,a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	int l=1,ans=1;
	ll w=0;
	for(int r=2;r<=n;r++){
		if(a[r]==a[r-1]){
			ans=max(ans,r-l+1);
			continue;
		}
		w+=(a[r]-a[r-1])*(r-l);
		while(w>m&&l<=r) w-=a[r]-a[l],l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
/*
答案显然是一段区间双指针随便做就做完了。
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
14:51过了小样例
14:55过了所有大样例 
试了一发空间就花了5MB，就这吧 
*/
