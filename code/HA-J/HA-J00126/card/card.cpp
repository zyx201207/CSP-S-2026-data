#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000001],b[1000001];
int head=1,tail=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 	
		b[a[i]]=n-i+1;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}

