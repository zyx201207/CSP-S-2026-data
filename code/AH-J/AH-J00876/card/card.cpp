#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],z[300001],v[300001];
int b[500001],c[500001],b1=0,c1=0;
int xy(int x){
    for(int k=1;k<=c1;k++){
	    if(c[k]==x)return k;	
	}	
	return c1+1;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
	    cin>>a[i];	
	}
	for(int i=1;i<=n;i++){
	    for(int j=i;j<=n;j++)b[++b1]=a[j];
		for(int j=1;j<i;j++)c[++c1]=a[j];
		for(int j=1;j<=b1;j++){
			int q=xy(b[j]);
			if(q>c1)c[++c1]=b[j];
			else{
		        for(int k=q;k<=c1;k++)c[k]=0;
		        c1=q;
		        c[c1]=b[j];
		    }
		}
		for(int j=1;j<=c1;j++)v[c[j]]=1;
		for(int j=1;j<=m;j++){
		    if(v[j]==1)z[j]++;
	    }
	    b1=0;
	    c1=0;
	    for(int j=1;j<=m;j++)v[j]=0;
	    for(int j=1;j<=n;j++){
		    b[j]=0;
		    c[j]=0;	
		}
	}
	for(int i=1;i<=m;i++)cout<<z[i]<<" ";
    return 0;
}
