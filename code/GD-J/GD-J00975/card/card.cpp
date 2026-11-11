#include<bits/stdc++.h>
using namespace std;
int a[500010];
int b[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
