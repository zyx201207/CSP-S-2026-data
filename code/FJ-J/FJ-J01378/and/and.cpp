#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],sum;
int main(){
  	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	sum=a[n];
	for(int i=0;i<m;i++){
		sum=sum&a[n-i];
	}cout<<sum;
	return 0;
}
