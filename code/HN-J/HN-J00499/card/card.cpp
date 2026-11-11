#include<bits/stdc++.h>
using namespace std;
struct jj{
	int w=0,f=0;
}l[30010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[50010],b[50010],h=0,c[30010]={};
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      cin>>a[i];
    for(int g=1;g<=n;g++){
    	int b[50010]={};
    	h=0;
    	for(int i=g;i<=n;i++){
    		h++;
    		if(l[a[i]].f==0){
    			b[h]=a[i];
    			l[a[i]].w=h;
    			l[a[i]].f=1;
			}
			else{
				for(int j=l[a[i]].w+1;j<h;j++)
				  l[a[j]].f=0;
				h=l[a[i]].w;
			}
		}
		for(int i=1;i<=h;i++){
			c[b[i]]++;
		}
		if(g<n){
		  for(int i=1;i<=m;i++)
		    l[i].f=0;
		}
	}  
	for(int i=1;i<=m;i++)
	  cout<<c[i]<<" ";
	return 0;
}

