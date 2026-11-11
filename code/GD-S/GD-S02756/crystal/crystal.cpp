#include <bits/stdc++.h>
using namespace std;
int main(){
//freopen("crystal.in","r",stdin);
//freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int z=0;
	for(int i=0;i<n;i++){
		if(a[i+1]-a[i]<=m){
			z+=a[i+1]-a[i];
			a[i]==a[i+1];
		}
		else{
			break;
		}
	}
	cout<<z;
	return 0;
}
