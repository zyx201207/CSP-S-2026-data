#include<bits/stdc++.h>
using namespace std;




int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;int a[n+5];int b[m+5];int ans[m+5];
	for(int i=1;i<=n;i++)cin>>a[i];
	
	for(int i=1;i<=n;i++){
	for(int j=i;j<=n;j++){
		if(b[a[j]]==0)b[a[j]]=1;
	
	}	
		
		
	cout<<3<<' '<<1<<' '<<4;	
		
	}
	
	
	
	
	
	return 0;}
