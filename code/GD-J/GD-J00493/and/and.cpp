#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a[100001]={},n,m,maxx=1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	maxx=a[n-1];
	for(int i=n-1;i>=n-m;i--){
		maxx&=a[i];
	}
	cout<<maxx; 
	return 0;
}
