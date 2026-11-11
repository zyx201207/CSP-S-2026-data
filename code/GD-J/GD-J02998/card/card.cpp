#include<bits/stdc++.h>
using namespace std;
int ma[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[n];
		ma[a[n]]++;
	}	
	for(int i=1;i<=m;i++){
		cout<<ma[i]<<" ";
	}
	
	return 0;
}
