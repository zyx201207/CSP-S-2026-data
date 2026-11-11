#include<bits/stdc++.h>
using namespace std;
int n,m,a[123456789],b[123456789],ans[111111];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		ans[m]=0;
	}	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==0){
	 cout<<0;}
	else{
	for(int i=1;i<=n;i++){
		int numn=0;
		for(int j=i;j<=n;j++){
			numn++;
			b[j]=a[j];
			for(int h=1;h<=j;h++){
				if(b[j]==b[h]){
					for(int d=h;d<numn;d++){
						b[d]=0;
					}
					numn=h;}
				}
				}
				for(int k=1;k<=n;k++) if(b[k]!=0) ans[b[k]]++;
		}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";}		
return 0;}
