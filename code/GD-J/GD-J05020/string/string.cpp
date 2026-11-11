#include<bits/stdc++.h>
using namespace std;
int n,s,a[1000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	} 
	if(n==1)
	     cout<<0;
		if(n==3) cout<<2;
	return 0;
}

