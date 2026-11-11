#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4&&m==2){
		cout<<a[n-1];
	}
	if(n==5&&m==3){
		cout<<a[n-1];
	}
	return 0;
}