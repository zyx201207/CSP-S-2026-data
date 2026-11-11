#include <bits/stdc++.h>
using namespace std;
long long n,m,sum;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	long long a[n];
	for(int i = 0;i < n;i++)cin >> a[i];
	sort(a,a+n);
	long long cha[n-1];
	for(int i = 1;i < n;i++){
		cha[i-1]=a[i]-a[i-1];
	}
	sort(cha,cha+n-1);
	for(long long i = 0;i < n-1;i++){
		if(m<cha[i])break;
		else{
			sum++;
			m-=cha[i];
		}
	}
	cout << sum;
	return 0;
} 
