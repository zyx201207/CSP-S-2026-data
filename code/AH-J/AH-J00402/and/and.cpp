#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	int n,m;
	cin>>n>>m;
for (int i=0;i<n;i++){
	cin>>a[i];
}
sort(a,a+n);
int b=n/2;
cout<<a[b];	



	return 0;	
} 	
