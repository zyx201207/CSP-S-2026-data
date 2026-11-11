#include<bits/stdc++.h>
using namespace std ;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long num=0;
	for(int i=n-1;i>=1;i--){
		cout<<1;
		long long x = m;
		int j = i-1;
		long long ans = 1;
		while (a[i] - a[j] <= x && j>=0){
			cout<<a[i]<< " "<<a[j]<<" ";
			x -= a[i] - a[j];
			ans ++;
			j--;
		}
		cout<<endl;
		if (ans > num) num = ans ;
	}
	cout<<num;
	return 0;
}
