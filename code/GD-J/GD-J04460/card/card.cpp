#include<bits/stdc++.h>
using namespace std;
int a[300005];
int b[500005];
int js[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			js[b[j]]+=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<js[i]<<" ";
	}
	return 0;
}
