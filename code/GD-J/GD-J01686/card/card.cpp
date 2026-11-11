#include<bits/stdc++.h>
using namespace std;
int const M=5e5;
int a[M];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cout<<n-a[i]+1<<" ";
	}
	return 0;
}
