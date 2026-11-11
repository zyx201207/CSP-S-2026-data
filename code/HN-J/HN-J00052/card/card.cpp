#include<bits/stdc++.h>
using namespace std;
int const mod=5e5+10;
long long a[mod],b[mod],c[mod];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,m,x=0;
	cin>>n>>m;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if(a[j]!=a[i]){
				c[j]=a[j];
			}
			if(a[j]==a[i]){
				for(int k=i; k<j; k++){
					c[k]=0;
				}
			}
		}
		for(int j=0; j<n+1; j++){
			b[c[j]]++;
		}
	}
	for(int i=1; i<=m; i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
