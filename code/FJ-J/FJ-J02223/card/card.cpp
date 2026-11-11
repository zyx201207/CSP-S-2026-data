#include <bits/stdc++.h>
using namespace std;
int a[100005];
int desk[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			if(desk[j]==desk[i]){
				for(int k=j;k<n;j++){
					desk[k] = 0;
				}
				desk[j] = a[i-1];
			}
			else{
				desk[i] = a[i-1];
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<desk[i];
	}
}
