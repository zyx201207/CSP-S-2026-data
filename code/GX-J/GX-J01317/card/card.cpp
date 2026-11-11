#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m,a[1000+5],b[1000+5],c[1000+5];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		c[i]=0;
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)b[i]=i;
	for(int i=1;i<=n;i++){
		cout<<i<<":";
		for(int j=i;j<=n;j++)cout<<a[j];
		cout<<endl;
		 
	}
	
	return 0;
}
