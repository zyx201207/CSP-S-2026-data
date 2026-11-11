#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,a[500001],ma=0;
	long long m,g=1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long sum=0;
	for(int i=1;i<n;i++){
		g=1;
		sum=0;
		for(int j=0;j<i;j++){
			sum+=a[i]-a[j];
		}
		if(sum>m){
			break;
		}
		ma=i+1;
	}
	cout<<ma;
	return 0;
}
