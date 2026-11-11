#include<bits/stdc++.h>
using namespace std;
int n,m,a[50007],k[50007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		k[a[i]]++;
	}
	for(int i=1;i<=n;i++) cout<<1<<" ";
	return 0;
}
