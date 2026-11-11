#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[300005];
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
	    int d[500005];
	    for(int i=1;i<=m;i++){
	    	c[i]=0;
	    }
		for(int j=i;j<=n;j++){
			d[j]=a[j];
			if(c[d[j]]==0) c[d[j]]=1;
			else for(int t=j-1;t>=i;t--){
				if(d[t]==d[j]) {
					d[j]=0;
					break;
				}
				d[t]=0;
				c[d[j]]=0;
			}
			
		}
		for(int j=i;j<=n;j++){
			cout<<d[j]<<" ";
			b[d[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
