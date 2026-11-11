#include<bits/stdc++.h>
using namespace std;
long long a[500005],m,sum[500005],ans = 1;
long long f(int x){
	return sum[x] - sum[x+1];
}
long long g(int x,int y){
	return sum[x]-sum[y+1]-f(y)*(y-x+1);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = n-1; i >= 1; i--){
		sum[i] = a[n] - a[i];
		sum[i] += sum[i+1];
	}
	for(long long i = n; i > 1; i--){
		int p = i-1;
		for(long long j = 19; j >= 0; j--){
			int tmp = p - (1 << j);
			if(tmp >= 1){
				if(g(tmp,i) <= m) p = tmp;
			}
		}
		//cout<<p<<" "<<i<<endl;
		ans = max(ans,i - p + 1);
	}
	cout<<ans;
	return 0;
}
