#include <bits/stdc++.h>
using namespace std;
long long a[300005],b[300005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i]+b[i-1];
	}
	int sum;
	for(int i=1;i<n;i++){
		if(b[i]>m){
			sum=i;
			break;
		}
	};
	cout <<sum;
	return 0;
}
