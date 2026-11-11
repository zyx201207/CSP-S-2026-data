#include<bits/stdc++.h>
using namespace std;
int n,m,a[11111111],sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		sum=max(a[i],sum);
	}
	cout<<sum;
	return 0;
} 
