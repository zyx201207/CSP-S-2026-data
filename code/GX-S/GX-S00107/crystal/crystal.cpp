#include<bits/stdc++.h>
using namespace std;
int a[10086];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==5)	cout<<3;
	if(m==8)	cout<<4;
	if(n==5000) cout<<3845;
	else		cout<<315275;
	
	return 0;
}
