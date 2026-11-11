#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+10;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int a[MAXN];
bool check(int x,int m){
	int res=0;
	for(int i=1;i<x;i++){
		int val=a[x]-a[i];
		res+=val;
	}
	return res<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=read(),m=read(),l=1,r=n;
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid,m))l=mid;
		else r=mid-1;
	}
	printf("%lld\n",l);
	return 0;
}
