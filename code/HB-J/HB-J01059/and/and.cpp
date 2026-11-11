#include<bits/stdc++.h>
using namespace std;
int n,m,a[200100],i=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+i+1);
	cout<<a[i-m+1];
}
		
			
		
