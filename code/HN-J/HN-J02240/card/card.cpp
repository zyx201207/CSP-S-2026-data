#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,x=0;
	cin>>n>>m;
	int a[n],js[m];
	for(int i=0;i<n;i++){
		cin>>a[i]; 
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i]!=a[j]){
				js[x]=a[i];
				x++;
			}
		}
	}
	return 0;
}
