#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[200010],maxz,s;
int main(){ 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(m==1){ 
		cout<<a[n-1]<<" ";
	} 
	return 0;
}
