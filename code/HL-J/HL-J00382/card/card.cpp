#include<bits/stdc++.h>
using namespace std;
int a[10000005];
int n,m;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cout<<n-i<<" ";
	}
	//fclose(stdin);
	//0fclose(stdout);
	return 0;
}
