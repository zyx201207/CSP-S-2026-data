#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
int n;
long long m;
long long a[N];
long long sum[N];
long long ans;



int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];	
	}
	sort(a+1,a+1+n);
	if(n<=5000){
		long long maxans = 1;
		for(int i=2;i<=n;i++){
			ans = 1;
			int j=i-1;
			long long k = m;
			while(k>=(a[i]-a[j])&&j>0){
				k-=(a[i]-a[j]);
				j--;
				ans++;
			}
			maxans = max(ans,maxans);
		}
		cout << maxans;
	}else{
		long long dis = a[2]-a[1];
		ans = 1;
		long long minus = dis;
		while(m>=minus){
			m -= minus;
			ans++;
			minus += dis;
		}
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
