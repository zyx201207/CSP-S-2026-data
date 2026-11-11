#include<bits/stdc++.h>
using namespace std;
int n,m;
long long gg[200005],sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>gg[i];
	}
	sort(gg+1,gg+n+1);
	sum=gg[n];
	for(int i=n;i>=n-m+1;i--){
		sum=sum&gg[i];
	}
	cout<<sum;
} 
