#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[300005];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=i;
	}
	for(int i=1;i<=m;i++)
		if(b[i])
			cout<<b[i]<<' ';
	return 0;
}
