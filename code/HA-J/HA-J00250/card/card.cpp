#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],l[300005],w[300005],v[300005];
long long c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[a[i]]++;
		l[a[i]]=i;
		c[a[i]]+=i;
	}
	for(int i=1;i<=n;i++){
		if(v[a[i]]>=2){
			v[a[i]]--;
			for(int j=i;j<=l[a[i]]-1;j++)w[j]=i;
		}
	}
	for(int i=1;i<=n-1;i++)c[a[i]]-=w[i];
	for(int i=1;i<=m;i++)cout<<c[i]<<" ";
	return 0;
}
