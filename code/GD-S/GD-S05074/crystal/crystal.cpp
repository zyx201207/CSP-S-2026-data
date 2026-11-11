#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
long long n,m,a[maxn],ans=-1,runtime,f;
long long cha;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	if(n<6000){
		ans = -1;
		for(long long i = 1;i <= n;i++){
			cin >> a[i];
		}
		sort(a+1,a+1+n);
		for(long long i = 1;i < n;i++){
			f = m;
			runtime = 1;
			for(long long j = i;f>=0&&j<=n;j++){
				f -= (a[j+1]-a[j])*j;
				if(f>=0){
					runtime++;
				}
			}
			ans = max(ans,runtime);
		}
		cout << ans;
	}
	else{
		for(long long i = 1;i <= n;i++){
			cin >> a[i];
		}
		sort(a+1,a+1+n);
		cha = a[2]-a[1];
		f = m;
		runtime = 1;
		for(int i = 1;f>0&&i<=n;i++){
			f -= cha*i;
			if(f>=0){
				runtime++;
			}
		}
		ans = max(ans,runtime);
		cout << min(ans,n);
	}
	return 0;
} 
