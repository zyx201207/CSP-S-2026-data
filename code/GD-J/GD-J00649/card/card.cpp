#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000001],x[10000001],y[10000001],z[100000001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			x[j]=0;
			y[j]=0;
		}
		for(int j=i;j<=n;j++){
		   x[a[j]]++;
		   if(x[a[j]]==2){
		   	    for(int k=y[a[j]];k<j;k++){
		   	 	    if(x[a[k]]>0 )x[a[k]]--;
			    }
		    }
			y[a[j]]=j; 
		}
		for(int j=1;j<=m;j++){
			if(x[j]==1) z[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<z[i]<<" ";
	}
} 
