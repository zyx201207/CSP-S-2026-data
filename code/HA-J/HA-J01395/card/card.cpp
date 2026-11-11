#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[300005];
int main(){
	freopen ("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[a[i]]++;
	}
	sort(c+1,c+m+1);
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
