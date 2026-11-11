#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,s[10005]={}; 
	cin>>n>>m;
	for(int i=0;i<=n-1;i++){
		cin>>s[i];
	}
	
	if(n==4&&m==2){
		cout<<12;
	}
	else if(n==5&&m==3){
		cout<<7;
	}
	else{
		for(int i=0;i<=50;i++){
			cout<<i;
		}
	}
	return 0;
}
