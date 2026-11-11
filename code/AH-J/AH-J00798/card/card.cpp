#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
int b[200005];
int v[100005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof v);
		for(int j=i;j<=n;j++){
			if(v[a[j]])
				for(int t=v[a[j]];t<j;t++)
					v[t]=0;
			v[a[j]]=j;
		}
		for(int j=1;j<=m;j++)
			if(v[j])
				b[j]++;
	}
	for(int j=1;j<=m;j++)
		cout<<b[j]<<" ";
	return 0;
}
//tuiyiwansui!!!
