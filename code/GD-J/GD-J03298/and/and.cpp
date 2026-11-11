#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
const int inf=(1<<30)-1;
int n,m;
int a[N];
int b[N];
int ans=0;
void dfs(int i,int s,int p) {
	if(p==m) {
		ans=max(ans,s);
		return ;
	}
	if(i==n+1)return ;
	dfs(i+1,s,p);
	dfs(i+1,s&a[i],p+1);
}
bool ch(int x){
	while(x){
		if((x&1)==0)return 0;
		x>>=1;
	}
	return 1;
}
bool ch2(int x){
	for(int i=0;i<=20;i++){
		if((1<<i)==x)return 1;
	}
	return 0;
}
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool f=1,f2=1;
	int c0=0,c1=0,c2=0,c3=0,c4=0;
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		if(!ch(a[i]))f=0;
		if(f2!=i-1)f2=0;
		if(a[i]==0)c0++;
		if(a[i]==1)c1++;
		if(a[i]==2)c2++;
		if(a[i]==3)c3++;
		if(c[i]==4)c4++;
	}
	if(n<=20) {
		dfs(1,inf,0);
		printf("%d",ans);
	} else if(m==1) {
		printf("%d",*max_element(a+1,a+1+n));
	} else if(m==2) {
		int ans=0;
		for(int i=1; i<=n; i++)
			for(int j=i+1; j<=n; j++)
				ans=max(ans,a[i]&a[j]);
		printf("%d",ans);
	} else if(n==m) {
		int ans=a[1];
		for(int i=2; i<=n; i++) {
			ans&=a[i];
		}
		printf("%d",ans);
	} else if(n==m+1) {
		b[1]=a[2];
		for(int i=2; i<=n; i++)b[i]=a[1];
		for(int i=2; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				if(i==j)continue;
				b[j]&=a[i];
			}
		}
		printf("%d",*max_element(b+1,b+1+n));
	}else if(f){
		sort(a+1,a+1+n);
		printf("%d",a[n-m+1]);
	}else if(*max_element(a+1,a+1+n)<=4){
		if(c4>=m)cout<<4;
		else if(c3>=m)cout<<3;
		else if(c2>=m)cout<<2;
		else if(c3+c1>=m)cout<<1;
		else cout<<0;
	}else {
		dfs(1,inf,0);
		printf("%d",ans);
	}
	return 0;
}
/*

4 3
2 1 2 3

*/
