#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+10],b=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==i) b=1;
	}
	if(b=1){
		if(m%2!=0) cout<<m;
		else cout<<m-1;
	}
	
    return 0;
} 
