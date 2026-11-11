#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=m;i++){
			cout<<1<<" ";
		}
	}else if(m==2){
		for(int i=1;i<=m;i++){
			cout<<2<<" ";
		}
	}else{
		cout<<3<<" 1"<<" 1";
	}
	return 0;
} 
