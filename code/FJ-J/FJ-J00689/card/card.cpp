#include<bits/stdc++.h>
using namespace std;
int a[500005],b[200005];
int n,m,z;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}if(n<=2){
		if(a[1]!=a[2])cout<<2<<" "<<2;
		else cout<<1;
	}
	for(int i=1;i<m;i++){
		cout<<n-b[i];
	}cout<<b[n];
}
