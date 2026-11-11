#include <bits/stdc++.h>
using namespace std;
long long a[10010];
int main(){
	long long n,m;
	cin>>n>>m;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>sum){
			sum=a[i];
		}
	}
	cout<<sum;
	return 0;
}
