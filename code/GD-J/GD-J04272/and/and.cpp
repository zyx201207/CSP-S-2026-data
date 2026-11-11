#include<bits/stdc++.h>
using namespace std;
long long i,a[200005],sum=0,t=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int j=1;j<=n;j++){
		cin>>a[j];	
	}
	if(t>sum) sum=t;
	cout<<sum;
	return 0;
} 
