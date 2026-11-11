#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,l,r;
int a[500009],c[500009];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int j=1;j<=m;j++){
		for(int i=n;i>=1;i--){
			if(a[j]==a[i]){
				c[j]=i;	
			}
		}
	}
	for(int j=1;j<=m;j++){
		cout<<c[j]+1<<" ";
	}
}


