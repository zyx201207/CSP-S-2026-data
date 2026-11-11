#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],v[N],st[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		st[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(st[a[j]]>j)j=st[a[j]];
			v[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<v[i]<<" ";
	return 0;
}

