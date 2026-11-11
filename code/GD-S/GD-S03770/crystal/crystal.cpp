#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n,m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	long long ma=-1e18;
	for(int i=1;i<=n;i++){
		long long ans=0;
		for(int x=i;x<n;x++){
			if(m>=(x-i+1)*(a[x+1]-a[x])){
				m-=(x-i+1)*(a[x+1]-a[x]);
				ans++;
				a[x]=a[x+1];
				while(a[x+2]==a[x+1]){
					x++;
					ans++;
				}
			}
			else{
				break;
			}
		}
		if(ma<ans){
			ma=ans;
		}
	}
	printf("%lld",ma+1);
	return 0;
} 
/*
数据量：5e5
期望时间:O(n)
算法：贪心
贪相对差值？数据大小？ 
*/
