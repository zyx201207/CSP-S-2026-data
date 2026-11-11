#include<bits/stdc++.h>
using namespace std;
int a[10005][10005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int n,k;
		cin>>n>>k;
		for(int j=0;j<n;j++){
			int u,v;
			a[u][j]=v;
		}
		cout<<n-1;
	}
	return 0;
}
