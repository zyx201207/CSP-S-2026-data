#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],b[100005],f[100005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int inx=1;
		for(int j=inx;j<=n;j++){
			b[i]=a[i];
			if(a[j]==i){
				inx=i;
			}
		} 
		f[b[i]]++;
		
	}
	for(int i=1;i<=m;i++){
		if(f[i]==' '){
			continue;
		}
		cout<<f[i]<<" ";
	}
	
	
	return 0; 
	
}
