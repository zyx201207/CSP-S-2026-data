#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[300001];
int main(){
	freopen("card1.in","r",stdin);
	freopen("card1.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
	        b[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
}
