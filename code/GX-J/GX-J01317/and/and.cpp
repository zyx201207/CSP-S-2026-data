#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m,a[10000+5],sum=0;
	cin>>n>>m;
	cin>>a[1]>>a[2];
	sum=a[1] and a[2];
	for(int i=3;i<=n;i++){
		cin>>a[i];
		sum=a[i] and sum;
	}
	cout<<sum;
	return 0;
}
