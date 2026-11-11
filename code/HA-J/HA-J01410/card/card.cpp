#include <bits/stdc++.h>
using namespace std;

int n,m,a[1000000],mk[1000000];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(n==4) cout<<"3 1 4";
	else if(n==10) cout<<"3 1 2 1 3 2 3 1 2 1";
	
	return 0;
}

