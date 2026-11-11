#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[300005];
int d[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int c=0;
	for(int i=1;i<=n;i++){
		int f=0;
		for(int k=i;k<=n;k++){
			c++;
			for(int j=1;j<c;j++){
		    	if(a[k]==d[j]){
			   	    c=j;
			   	    break;
		        }
		    }
		    d[c]=a[k];
		}
		for(int j=1;j<=c;j++){
			b[d[j]]++;
		}
		c=0;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
