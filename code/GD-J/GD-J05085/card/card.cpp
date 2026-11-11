#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[500005],ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
 	cin>>n>>m;
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
	} 
	for(int k=1;k<=n;k++){
		for(int i=k,j=1;i<=n;i++,j++){
		 	b[j]=a[i];
			c[b[j]]++;
		 	if(c[b[j]]>1){
		 		for(int p=1;p<=m;p++){
		 			c[p]=0;
				}
				c[b[j]]++;
				for(int q=1;q<=j;q++){
					b[q]=0;
				}
		 		j=1;
		 		b[j]=a[i];
			}
		}
		for(int i=1;i<=m;i++){
			if(c[i]!=0){
				ans[i]++;
			}
		}
		for(int i=1;i<=m;i++){
			c[i]=0;
		}
		for(int i=1;i<=n;i++){
			b[i]=0; 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' '; 
	}
	return 0;
} 
