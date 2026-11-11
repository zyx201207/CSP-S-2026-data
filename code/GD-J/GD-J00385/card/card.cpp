#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300050],c[300050];
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int b[300050]={};
		for(int j=i;j<=n;j++){
			b[a[j]]++;
		}
		for(int j=i;j<=n;j++){
			if(b[a[j]]%2==1)c[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << c[i]<<' ';
	}
	
	
	return 0;
} 
