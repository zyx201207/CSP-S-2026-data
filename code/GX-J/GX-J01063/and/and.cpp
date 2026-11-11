#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2e5+10;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x;
}
int a[MAXN];
bool cmp(int x,int y){
	return x>y;
}
int ans,maxx=-1;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans&=a[i];
	}
	maxx=ans;
	int x=1;
	while(x+m-1<=n){
		ans|=a[x];
		x++;
		ans&=a[x+m-2];
		maxx=max(maxx,ans);
	}
	//for(int i=1;i<=m+10;i++)cout<<a[i]<<" ";
	printf("%lld\n",maxx);
	return 0;	
}
