#include<bits/stdc++.h>
using namespace std;
int a[500005];
#define int long long

int n,m,t;//t记录小水晶个数 
int check(int x){//返回用该基准能得到的相同小水晶数量 
	t = 0;
	int wei = upper_bound(a,a+n,x)-a;
	int cao = 0;
	for(int i=wei-1;i>=0;i--){//从基准往后面遍历 
		cao += x-a[i];
		if(cao>m)return t;
		else t++;
	}
	return t;
} 


signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	sort(a,a+n);
	int maxx = 0;
	for(int i=a[n-1]+1;i>=a[0];i--){
		if(maxx==n)break;
		else if(check(i)>=maxx)maxx=check(i); 
	}
	printf("%lld\n",maxx);
	return 0;
}
