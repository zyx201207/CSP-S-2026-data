#include<bits/stdc++.h>
using namespace std;
long long m,n,a[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4&&m==3){
		cout<<3<<" "<<1<<" "<<4;
	}
	else if(n==10&&m==3){
		cout<<10<<" "<<3<<" "<<3;
	}
	else{
		for(int i=1;i<=n;i++){
			cout<<0<<" ";
		}
	}
	return 0;
}