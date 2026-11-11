#include<bits/stdc++.h> 
using namespace std;
long long a[100000000+10];
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	long long x=m;
	sort(a+1,a+n+1);
	long long mid=(n+1)/2;
	long long sum=0;
	for(int i = mid;i>=1;i--){
		if(m>=(a[mid]-a[i])){
			sum++;
			m-=(a[mid]-a[i]);
			continue;
		}
		cout << sum;
		return 0;
	}
	for(int i = mid+1;i <= n;i++){
		if(a[i]==a[mid])
		{
			sum++;
			mid++;
		}
	}
	while(m!=0&&mid<n&&(m-(mid*(a[mid+1]-a[mid])))>=0){
		sum++;
		m-=(mid*(a[mid+1]-a[mid]));
		mid++;
	}
	cout << sum;
	return 0;
}
