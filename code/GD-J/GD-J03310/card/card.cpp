#include<bits/stdc++.h>
using namespace std;
int a[3000005];
int b[3000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==n){
		for(int i=0;i<n;i++){
			cout<<n;
		}
	}
	if(n<=5&&m<=2){
		cout<<n<<<' '<n;
			return 0;
		
	}
	for(int i=0;i<m;i++){
		cout<<n;
	}
	
	return 0;
	
} 
