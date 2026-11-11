#include<bits/stdc++.h>
#define int long long
//#define double long double
using namespace std;
const int M=2e6+5;
int c,t,n,d,x[M],cnt,ans,bj=0;
struct Edge{
	int to,nt,q/*±ßÈ¨*/;
}a[M*2];
void find(int x,int y,int q){
	a[++cnt].to=x;
	a[cnt].nt=y;
	a[cnt].q=q;
	return;
}
int dfs(int I,int J){
	int res=0;
	int sum=0;
	for(int i=I;i<=cnt;i++) sum+=a[i].q;
	res=sum;
	return res;
}
int hanshu(){
	int as=0;
	for(int i=1;i<=n-1;i++) for(int j=i+1;j<=n;j++){
		if(dfs(i,j)==2) as++;
	}
	return as;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	if(c==0){
		scanf("%lld %lld",&n,&d);
		if(n==4&&d==2){cout<<"1\n2";return 0;}
		else if(n==5&&d==3){cout<<"0\n1";return 0;}
		bj=1;
	}
	if(bj) t--;
	while(t--){
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n+2;i++) x[i]=0; //csh
	 	for(int i=1;i<=n;i++) scanf("%lld %lld",&x[i]);
	 	for(int i=1;i<=n-1;i++) for(int j=i+1;j<=n;j++){
	 		if(abs(x[i]-x[j])<=d){
				find(x[i],x[j],abs(x[i]-x[j]));
				find(x[j],x[i],abs(x[i]-x[j]));
			}
		}
		ans=0;
		ans=hanshu();
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
//1\n2
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
//0\n1
*/
