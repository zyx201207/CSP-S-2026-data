#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//Trick||Treat!
	int n,m;
	cin>>n>>m;
	int a[200005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a+0,a+n);
	int cnt=a[n-1];
	for(int i=n-2,j=0;j<m-1;j++,i--){
		cnt=a[i];
	} 
	cout<<cnt;
	return 0;
} 
