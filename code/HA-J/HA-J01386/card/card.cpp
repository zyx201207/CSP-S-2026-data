#include<bits/stdc++.h>
using namespace std;
int a[500005],x[500005],w[300005],g[300005];
int main(){
	// d
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){   
		cin>>a[i];
	}
	int p=1,h=0;
	while(p<=n){   
		for(int i=p;i<=n;i++){   
			x[h]=a[i];
			w[a[i]]++;
			h++;
			if(w[a[i]]==2){
				h=0;
				w[a[i]]==1;
				x[h]=a[i];
				h++;
			}
		for(int j=1;j<=m;j++){
			if(w[j]==1){
				g[j]++; 
			}
		}
		p++;
		h=0;
		}
	}
	g[n]++; 
	for(int i=1;i<=m;i++){
		cout<<g[i]<<" ";
	} 
	return 0;
}

