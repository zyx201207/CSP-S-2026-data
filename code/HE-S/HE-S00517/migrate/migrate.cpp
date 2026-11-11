#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 2e6 + 10;

LL a[N],sum[N],sum1[N];
int C,T;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		int n;
		LL m;
		cin>>n>>m;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
			sum[i] = 1;
			if(a[i] - a[i - 1] <= m) sum[i] += sum[i - 1];
			//cout<<sum[i]<<'\n';
			if(i >= 3&&a[i] - a[i - 2] <= m){
				//cout<<i<<'\n';
				sum[i - 2] = 1;
				sum[i - 1] = 1;
				sum[i] = 1;
			} 
		}
		sum1[n + 1] = 0;
		for(int i = n;i >= 1;i--){
			sum1[i] = 1;
			if(a[i + 1] - a[i] <= m) sum1[i] += sum1[i + 1];
			if(i <= n - 2&&a[i + 2] - a[i] <= m) sum1[i + 2] = sum1[i + 1] = sum1[i] = 1;
		}
		//for(int i = 1;i <= n;i++) cout<<sum[i]<<' ';
		//puts(""); 
		LL ans = 0;
		a[n + 1] = 8e18;
		for(int i = 1;i <= n - 3;i++){
			//cout<<a[i + 3] - a[i] <<' '<< a[i + 4] - a[i]<<"\n"; 
			if(a[i + 2] - a[i] <= m&&a[i + 3] - a[i + 1] <= m&&a[i + 3] - a[i] > m){
				ans += sum[i] * sum1[i + 3];
//				int l = 1,r = 1;
//				for(int j = i - 1;j >= 1;j--){
//					if(a[j + 2] - a[j] <= m||a[j + 1] - a[j] > m) break;
//					l ++;
//				}
//				for(int j = i + 1;j <= n;j++){
//					if(a[j] - a[j - 2] <= m||a[j] - a[j - 1] > m) break;
//					r ++;
//				}
			}
		}
		cout<<ans<<'\n';
	}
	
	
	
	return 0;
} 
