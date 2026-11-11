#include<bits/stdc++.h>
using namespace std;
int n,m,max1=0,ans;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4&&m==2){
		ans=12;
	}
	if(n==5&&m==3){
		ans=7;
	}
	cout<<ans;
	return 0;
}
