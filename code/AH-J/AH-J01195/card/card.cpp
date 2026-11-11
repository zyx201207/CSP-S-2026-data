#include <bits/stdc++.h>
using namespace std;
int a[5000005],c[500005],b[500005];	
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		for(int k=1;k<=m;k++){
			b[k]=0;
		}
		for(int i=j-1;i<=n;i++){
			b[a[i]]++;
		}
		for(int f=1;f<=m;f++){
			if(b[f]!=0) c[f]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
 	return 0;
}
