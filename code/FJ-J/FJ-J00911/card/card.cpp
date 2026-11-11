#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],b[500005];
int vs[500005]; 
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(vs[a[i]]){
			b[vs[a[i]]]=i;
		}
		vs[a[i]]=i;
	}
	memset(vs,0,sizeof vs);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			while(b[j]){
				j=b[j];
			}
			if(b[j]==0){
				vs[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<vs[i]<<" ";
	}
	return 0;
}

