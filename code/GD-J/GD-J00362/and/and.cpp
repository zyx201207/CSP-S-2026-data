#include<bits/stdc++.h>
using namespace std;
int n,m,q=0;
int a[200005];
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]>q) q=a[i];
	}
	cout<<q;

		
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
