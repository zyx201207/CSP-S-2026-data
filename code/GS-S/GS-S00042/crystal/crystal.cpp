#include <bits/stdc++.h>
using namespace std;

long long a[1000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int sum=-1;
	long long t=m;
	for(int i=n;i>=1;i--){
		int cnt=1;
		m=t;
		for(int j=1;j<=i;j++){
			if(a[i]-a[i-j]<=m){
				m-=(a[i]-a[i-j]);
				cnt++;
			}
			else{
				break;
			}
		}
		if(cnt>sum) sum=cnt;
	}
	cout << sum;
	
	return 0;
}
