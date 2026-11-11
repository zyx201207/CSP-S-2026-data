#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int a[100005];
	int b[100005];
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int cnt=0;
		b[a[i]]++;
		
	} for(int j=1;j<=m;j++) cout<<b[j]<<' ';
	return 0;
}
