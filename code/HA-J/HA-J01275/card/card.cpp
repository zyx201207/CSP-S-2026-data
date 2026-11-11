#include<bits/stdc++.h>
using namespace std;
int a[200005]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[x]++;
	}
	for(int i=1;i<=m;i++)cout<<a[i]<<' ';
	
	
	return 0;
}

