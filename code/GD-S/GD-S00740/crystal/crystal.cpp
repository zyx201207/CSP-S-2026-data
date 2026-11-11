#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.in","r",stdin);
	long long n,m;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	sum[0]=0;
	int cnt=1;
	for(int i=2; i<=n; i++){
		sum[i-1]=(a[i]-a[i-1]);
	}
	int maxn=-1;
	for(int i=1; i<=n-1; i++){
		int ans=1;
		long long cnt=0;
		for(int j=i; j<=n-1; j++){
			cnt +=ans*sum[j];
			if(cnt<=m){
				maxn=max(maxn,j-i+2);
			}else{
				break;
			}
			ans++;
		}
	}
	cout << maxn;
	return 0;
}
