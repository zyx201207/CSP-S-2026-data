#include<bits/stdc++.h>
using namespace std;
long long n,m,ans = -1,k=0;
long long a[500005],cst[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		k+=a[i];
	}
	sort(a+1,a+1+n);
	long long step = 0,sum = 0;
	for(long long i = 1;i <= n;i++){
		step = 0;
		sum = 0;
		for(long long j = 1;j <= i;j++){ 
			if(j<=i) cst[j] = a[i]-a[j];
			else cst[j] = -1;
		}
		for(int j = i;j >= 1;j--){
			if(step+cst[j] <= m&&cst[j]!=-1){
				step += cst[j];
				sum++;
			}
		}
		if(sum > ans) ans = sum;
	}
	cout << ans;
	return 0;
}
