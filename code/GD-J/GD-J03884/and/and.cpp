#include<bits/stdc++.h>
using namespace std;
long long a[200001],b[200001],c=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+1+n);
	if(m<20){
		if(m==1){
			cout<<a[1];
		}
	
	}
	c=n;
	for(int i=n-1;i>=n-m;i--)c=c&a[i];
	cout<<c;
	return 0;
} 
