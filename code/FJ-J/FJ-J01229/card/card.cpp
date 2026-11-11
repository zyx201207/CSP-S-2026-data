#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010],c[500010];
int sz[500010];
int main(){
	int n,m;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int i=0;
	while(i<=n) {
		i++;
		cin>>a[i]; 
		sz[i]=a[i];
	} 

	for(i=1;i<=n;i++){
		int x=1;
		b[500010]={0};
		for(int j=i;j<=n;j++){
			for(int k=i;k<j;k++){
				if(a[j]==a[k]){
				b[500010]={0};
				x=1;
				b[x]=j;
				x++;
				}
				else b[x++]=j;
			}
			
		}
		for(int j=0;j<=n;j++){
			int ys=0;
			for(int k=0;k<=x;x++){
				if(b[x]==sz[j]) {
				
				ys++;
				break;}
			}
			cout<<ys;
		}
	}
	
	
return 0;	
}
