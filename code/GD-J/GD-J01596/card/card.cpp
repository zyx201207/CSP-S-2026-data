#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(a,0,sizeof(a));
	int n,m;cin>>n>>m;
	int last=0;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		a[x]++;
		last=x;
	}
	for(int i=1;i<=m;i++){
		if(last==i) cout<<n;
		else cout<<a[i];
		cout<<" ";
	}
	return 0;
}
