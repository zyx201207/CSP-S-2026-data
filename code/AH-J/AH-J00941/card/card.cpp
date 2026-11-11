#include<bits/stdc++.h>
using namespace std;
int md[1000005],c[1000005],a[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	for(int j=1;j<=m;j++){
		j=md[a[i]];
		c[a[j]]++;
	}
	
}
	for(int i=1;i<=m;i++){
	if(c!=0) cout<<c[i]<<" ";
}
	return 0;
}
