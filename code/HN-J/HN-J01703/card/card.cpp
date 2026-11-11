#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500],b[1000],c[1000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		b[i]=a[i];
		c[i]=b[i];
	}
	for(int i=1;i<=n;i++){
		b[i+n]=b[i];
		c[i+n]=b[i+n];
	}
	for(int i=1;i<=n;i++) cout<<n<<' '; 
	return 0;
}/*
4 3
1 2 1 3

4 3
1 2 3 4
*/
