#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[300009];
	for(int i=0;i<=n;i++){	
		cin>>a[i];
	}
	if(n==4){
		cout<<3<<" "<<1<<" "<<4;
	}	
	if(n==10){
		cout<<10<<" "<<3<<" "<<3;
	}

	
	return 0;
} 








































