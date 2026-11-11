#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n=0,m=0;
	cin>>n;
	cin>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(a[0]==a[1]){
		cout<<n;
		return 0;
	} 
	long long sum=0,num=0;
	for(int i=0;i<n;i++){
		num+=i;
		if(num>m){
			break;
		}
		sum++;
	}
	cout<<sum;

	return 0;
} 
