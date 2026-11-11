#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(m==1){
		cout<<a[1];
	}
	if(n==1){
		cout<<a[1];
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			cout<<a[i]<<" ";
		} 
	}
	return 0;
} 
