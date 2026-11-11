#include <bits/stdc++.h>
using namespace std;
int n,m,a[500050],b[500050],c[500050];
int main(){
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int g=50050;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int x=1;x<=g;x++){
				if(a[j]!=b[x]){
					b[j]=a[j];
				}
				else{
					b[x]=a[j];
					for(int y=x+1;y<=g;y++){
						b[y]=0; 
					}
				}
			}
			for(int e=1;e<=g;e++){
				if(b[e]!=0){
					c[b[e]]+=1;
				}
			}
		}
	}
	for(int i=1;i<=g;i++){
		if(c[i]!=0){
			cout<<c[i]<<' ';
		}
	}
	return 0;
} 
