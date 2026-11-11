#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(-x);
		return;
	}
	if(x>9)print(x/10);
	putchar(x%10+48);
}
int n,m,a[N],s[N],ans=1,l=1,r=n; 
bool chk(int x){
	for(int i=x;i<=n;i++){
		if(a[i]*x-(s[i]-s[i-x])<=m)return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();r=n;
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	while(l<=r){
		int mid=(l+r)>>1;
		if(chk(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	print(ans);
	return 0;
}

//¶þ·Ö 
