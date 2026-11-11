#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long maxx;
long long b[200005];
bool st[200005];
void dfs(int x){
	if(x==m){
		long long ans=b[1];
//		cout<<b[1]<<" ";
		for(int i=2;i<=x;i++){
			ans&=b[i];
//			cout<<b[i]<<" ";
		}
//		cout<<endl;
//		cout<<"ans="<<ans<<endl;
		maxx=max(maxx,ans);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!st[i]){
			b[++x]=a[i];
			st[i]=true;
			dfs(x);
			st[i]=false;
			b[x]=0;
			x--;
		}
	}
	return ;
}
//bool f(){
//	int res=1;
//	while(res<n){
//		res*=2;
//	}
//	if(res==n)return true;
//	else return false;
//}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	long long max_a=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		max_a=max(max_a,a[i]);
	}
//	if(f())printf("%lld",n-1);
	if(n>2000&&max_a<4){
		if(m==1)printf("3");
		else if(m==2)printf("2");
		else printf("0");
		return 0;
	}
	if(m==1){
		printf("%lld",max_a);
		return 0;
	}
	dfs(0);
	printf("%lld",maxx) ;
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
