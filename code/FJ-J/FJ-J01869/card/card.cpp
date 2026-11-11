#include<bits/stdc++.h> 
using namespace std;
long long a[500005],b[500005],c[500005],d,e,n,m,s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		b[a[i]]=i;
	}
	sort(b+1,b+m+1);
	for(int i=1;i<=m;i++){
		c[a[b[i]+1]]+=c[a[b[i]]];
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
