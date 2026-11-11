#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int sd;
	cin>>n>>m;
	struct node{int p;};
	int a[500005];
	int tmp;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		
	}
	if(n==1&&m==1){
		cout<<1;
		return 0;
	}else if(m==1){
		cout<<n;
	}else if(n==m){
		for(int i=1;i<=n;i++){
			cout<<i<<' ';
		}
	}else{
		
	}
	return 0;
} 
