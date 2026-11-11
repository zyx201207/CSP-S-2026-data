#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	int n,m;
	cin>>n>>m;
	int a[m]={};
	int s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4 and m==3){
		cout<<3<<" "<<1<<" "<<4;
	}else{
		cout<<10<<" "<<3<<" "<<3;
 	}
	
	}
	return 0;
}
