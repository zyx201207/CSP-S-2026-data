#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300015];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		for(int i=t;i<=m;i++){
			a[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
