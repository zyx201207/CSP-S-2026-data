#include<bits/stdc++.h> 
using namespace std;
int a[10001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>=1;j--){
			for(int k=1;k<=j;k++){
				if(a[j]==a[k]) 
			}
		}
	}
