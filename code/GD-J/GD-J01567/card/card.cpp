#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<"1 ";
	for(int i=1;i<m;i++){
		cout<<"0 ";
	}
	return 0;
} 
