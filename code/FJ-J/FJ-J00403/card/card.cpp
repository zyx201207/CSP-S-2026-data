#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],c[200005],d[200005],p=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			p=0;
		}
	}
	if(n<=500){
	    for(int i=1;i<=n;i++){
		    for(int j=i;j<=n;j++){
		    	c[j]=a[j];
			}
			for(int j=i;j<=n;j++){
				d[c[j]]++;
				if(d[c[j]]>1){
					for(int k=j-1;k>=i;k--){
						d[c[k]]--;
						if(c[k]==c[j]){
							c[k]=0;
							break;
						}
						c[k]=0;
					}
				}
			}
			for(int j=i;j<=n;j++){
				b[c[j]]++;
				d[c[j]]=0;
			}
	    }
	    for(int i=1;i<=m;i++){
	    	cout<<b[i]<<" ";
		}
    }else if(p==1){
    	for(int i=2;i<=n;i++){
    		if(a[i]!=a[i-1]){
    			d[a[i-1]]=i-1;
			}
			if(i==n){
				d[a[i]]=n;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<d[i]<<" ";
		}
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
