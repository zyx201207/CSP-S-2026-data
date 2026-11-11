#include<bits/stdc++.h>
using namespace std;
int n,t;
long long x[2000005],d;
int dc1[1000005];
int dc2[1000005];
int ans1,ans2,ans3;
void dfs(int a,int b,long long sum){
	if(a==b){
		if(sum>ans1) return;
		if(sum==ans1) ans2++;
		else ans2=1,ans1=sum;
		return;
	}
	
	for(int i=b;i>=a+1;i--)
		if(x[i]-x[a]<=d) dfs(i,b,sum+1);
}
void solve1(){
	for(int i=1;i<=n;i++)
		for(int j=i+3;j<=n;j++){
			ans1=ans2=0x3f3f3f3f;
			dfs(i,j,0ll);
			if(ans2==2){
				ans3++;
			}
		}
	cout<<ans3;
}
void solve2(){
	long long qwq=x[2]-x[1];
	long long ty=d/qwq;
	if(ty<2){
		cout<<"0\n";
		return;
	}
	cout<<max(0ll,-2*ty+n+1)<<'\n';
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		ans1=ans2=0x3f3f3f3f;
		if(n<=9) solve1();
		else solve2();
	}
	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

10 6
1 4 7 10 13 16 19 22 25 28

1 0
2 0
3 0
4 6(1 4,2 5,3 6,...)
5 6
6 4(1 6,2 7,3 8,4 9)
7 4
8 2
9 2
10 0


*/
