#include<bits/stdc++.h>
using namespace std;
int a[500200],b[500200];
int v[5050][3050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	    for(int j=1;j<=a[i];j++) b[j]++;
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}
