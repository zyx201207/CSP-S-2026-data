#include<bits/stdc++.h>
using namespace std;
int n,m; 
int a[500050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	cout<<n-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
