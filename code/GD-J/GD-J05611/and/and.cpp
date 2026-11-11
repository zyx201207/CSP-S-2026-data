#include<bits/stdc++.h>
using namespace std;
long long n,m,f[1000010],sum;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>f[i];
	}
	sort(f,f+n);
	sum=f[n];
	for(int i=n-1;i>m;i--){
		sum=f[i]&sum;
	}
	cout<<sum;
	return 0;
}
