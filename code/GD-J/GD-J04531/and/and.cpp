#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w"stdout);
	int n,m,a[10001];
	cin>>n>>m;
	int mini=1e9
	for(int i=0;i<n;i++){
		cin>>a[i]; 
		mini==min(mini,a[i]);
	} 
	cout<<mini;
}
