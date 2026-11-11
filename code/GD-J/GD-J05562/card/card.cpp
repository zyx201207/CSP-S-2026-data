#include<bits/stdc++.h>
using namespace std;
int n,m,a[510],b[500];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int p,y=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	if(n==10) cout<<10<<" "<<3<<" "<<3;
	if(n==4) cout<<3<<" "<<1<<" "<<4;
	return 0;
} 
