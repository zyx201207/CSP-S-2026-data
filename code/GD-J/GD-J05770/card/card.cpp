#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005],c[200005],d[200005],t=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		d[i]=a[i];
		 if(c[a[i]]==0){
		 	for(int j=n;j>=i;j--){
		 		if(d[j]!=0)b[d[j]]++;
			}
			c[a[i]]=1;
		 }else{
		 	for(int j=n;j>=i;j--){
				if(d[j]==a[i]){
					for(int o=j;o>=i+1;o--){
						d[o]=0;
						c[a[o]]=0;
					}
				}	
			}
			for(int j=n;j>=i;j--){
		 		if(d[j]!=0)b[d[j]]++;
			}
		 }
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
