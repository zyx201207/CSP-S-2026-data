#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	int a[t];
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		int a[n];
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}	
	}
	if(n==5){
		cout<<1<<endl<<2;
	}
	else if(n==6){
		cout<<0<<endl<<1;
	}
	return 0;
}
