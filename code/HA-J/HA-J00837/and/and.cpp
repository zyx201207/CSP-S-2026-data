#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
long long sum=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	sum=a[n];
	if(m>=2){
		for(int i=n;i>=n-m+1;i--){
			sum&=a[i];
		}
	}
	cout<<sum;
	return 0;
}

