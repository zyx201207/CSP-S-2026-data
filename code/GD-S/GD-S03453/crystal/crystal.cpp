#include<bits/stdc++.h>
using namespace std;
long long n,m,a[510000],maxx = -1,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i = 1;i <= m;i++){
		sort(a+1,a+n+1);
		a[1]++;
	}
	for(int i = 1;i <= n;i++){
		sum = 0;
		for(int j = 1;j <= m;j++){
			if(a[j] == a[i]){
				sum++;
			}
		}
		maxx = max(maxx,sum);
	}
	cout << maxx ;
	return 0;
} 
