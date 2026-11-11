#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[123445];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i){
			cout<<i;
			return 0; 
		}		
	}
	cout<<abs(a[1]+a[2]);
	return 0;	
}
