#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200005],sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	sum=a[n-m+1];
	for(int i=n;i>n-m+2;i--){
		int l=a[i]&sum;
		sum=l;
	}
	cout<<sum;
	return 0;
}
