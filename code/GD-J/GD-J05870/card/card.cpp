#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005],c[500005],d[300005];
int m,n,i,j,t;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	for(t=1;t<=n;t++){
		j=1;
		memset(c,0,sizeof(c));
		memset(b,0,sizeof(b));
		for(i=t;i<=n;i++){
			if(b[a[i]]==0){
				b[a[i]]=1;
				c[j]=a[i];
				j++;
			}
	    	else{
	    		 while(c[j-1]!=a[i]){
	    			b[c[j-1]]=0;
	    			c[j-1]=0;
	    			j--;
				}
			}
		}
		for(i=1;i<j;i++) d[c[i]]++;
	}
	for(i=1;i<=m;i++) cout<<d[i]<<" ";
	return 0;
}
/*
10 5 
1 2 3 1 2 5 4 3 4 3

1:1 2 5 4 3
2:2 5 4 3
3:3
4:1 2 5 4 3
5:2 5 4 3
6:5 4 3
7:4 3
8:3
9:4 3
10:3

2 4 10 7 5
*/
