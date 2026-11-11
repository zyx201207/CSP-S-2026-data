#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m,maxn=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(maxn<a[i]) maxn=a[i];	
	}
	cout<<maxn; 
	return 0;
} 
