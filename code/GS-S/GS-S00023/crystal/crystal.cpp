#include<iostream>
#include<algorithm>
#define int long long 
using namespace std;
const int N=5e5+1;
int a[N];
int n,m;


void solve1(){
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int ans=0;
	int l=1;
	int sum=0;
	for (int r=1;r<=n;r++){
		sum+=(a[r]-a[r-1])*(r-l);
		while (sum>m&&l<=n){
			sum-=a[r]-a[l];
			l++;
		}
		
		ans=max(ans,r-l+1);
		
	}
	printf("%lld\n",ans);
	
	
	
	
	return ;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	solve1();
	
	
	
	
	return 0;
}

/*
5 5
1 2 4 8 9

*/

/*
5 8
-3 -1 2 2 7

*/




