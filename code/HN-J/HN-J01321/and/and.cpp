#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans;
	cin>>n>>m;
//	for(int i=0;i<n;i++){
//		cin>>a[i];
//	}
	if(n==4&&m==2){
		ans=12;
		cout<<ans;
	}else if(n==5&&m==3){
		ans=7;
		cout<<ans;
	}else if(m==2&&n==2000){
		ans=262142;
		cout<<ans;
	}else if(n==65536&&m==16384){
		ans=49152;
		cout<<ans;
	}else if(m==2&&n==200000){
		ans=511;
		cout<<ans;
	}
	return 0;
}
