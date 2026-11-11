#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5+1;
int a[N],dp[N];
int n,m;
void solve1(){
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int ans=0;
	for (int i=0;i<(1<<n);i++){
		int k=0;
		int res=0;
		bool xym=true;
		for (int j=0;j<n;j++){
			if ((i>>j)&1){
				if (k==0) res=a[j+1];
				else res&=a[j+1];
				k++;
				if (k>m){
					xym=false;
					break;
				}
			} 
		}
		if (!xym) continue;
		if (k<m) continue;
		ans=max(ans,res);
	}
	printf("%d\n",ans);
}

void solve2(){
	int ans=0;
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		ans=max(ans,x);
	}
	printf("%d\n",ans);
	return ;
}

void solve3(){
	int ans=0;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		int res=0;
		for (int j=1;j<=n;j++){
			if (i==j) continue;
			res=max(res,a[i]&a[j]);
		}
		ans=max(res,ans);
	}
	printf("%d\n",ans);
	return ;
}

void solve4(){
	int ans=0;
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if (i==1) ans=x;
		else ans&=x;
	}
	printf("%d\n",ans);
	return ;
}

void solve5(){
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		int res=0;
		bool flag=true;
		for (int j=1;j<=n;j++){
			if (j==i) continue;
			if (flag) res=a[i];
			else{
				flag=false;
				res&=a[i];
			}
		}
		ans=max(ans,res);
	}
	printf("%d\n",ans);
	
	return ;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	solve5();
	
	return 0;
	if (n<=20) solve1();
	else if (n>20&&n<=2000&&m==1) solve2();
	else if (n>20&&n<=2000&&m==2) solve3();
	else if (n>20&&n<=2000&&m==n) solve4();
	else{
		solve5();
	}
	
	
	return 0;
}
