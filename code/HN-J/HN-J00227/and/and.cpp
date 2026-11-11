#include<bits/stdc++.h>
using namespace std;
struct A{
	long long s,c;
}b[200010];
long long n,m,a[200010],p[40],ans=0;
bool cmp1(int x,int y){
	return x>y;
}
bool cmp(A x,A y){
	if(x.s==y.s) return x.c>y.c;
	return x.s>y.s;
}
void dfs(long long now,long long sum,long long add){
	if(now==n+1){
		if(add==m) ans=max(ans,sum);
		return ;
	}
	dfs(now+1,sum&a[now],add+1);
	dfs(now+1,sum,add);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	p[0]=1;
	for(int i=1;i<=35;i++) p[i]=p[i-1]*2;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		dfs(1,1,0);
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1,cmp1);
	for(int i=1;i<=n;i++){
		long long mn=0x7fffffff;
		for(int j=1;j<=35;j++) mn=min(mn,abs(a[i]-p[j]));
		b[i].s=a[i];
		b[i].c=mn;
	}
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=m;i++){
		ans&=b[n-i+1].s;
	}
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/

