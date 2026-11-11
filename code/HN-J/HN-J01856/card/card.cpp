#include<bits/stdc++.h>
using namespace std;
int n,m,a[500000],b[500000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=a[i-1])b[a[i-1]]=i-1;
	}
	b[m]=n;
	for(int i=1;i<=m;++i)cout<<b[i]<<' ';
	return 0;
}
