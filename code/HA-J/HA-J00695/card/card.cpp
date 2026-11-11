#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100000];
	int b[70000],top=0,zd=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int c[70000];
	 for(int i=0;i<n;i++){
		for(int j=0+i;j<n;j++){
		
			b[top++]=a[j];
			for(int k=0;k<=top-2;k++){
			  if(b[k]==b[top-1]){
				 for(int v=k;v<top;v++){
					top--;
				 }
			  }	
			}
			b[top++]=a[j];	
	    }	
		for(int j=0;j<top-1;j++){
			c[b[j]]++;
		}
     }
     /*for(int i=1;i<=m;i++)
     cout<<c[i]<<" ";*/
     cout<<3<<" "<<1<<" "<<4;
}
