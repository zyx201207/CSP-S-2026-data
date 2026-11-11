#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],t,w,n,m;
int c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(c[a[j]]==0){
				c[a[j]]++;
			}
			else if(c[a[j]]==1){
				for(int k=i;k<j;k++){
					c[a[k]]=0;
				}
				c[a[j]]++;
			}
		}
		for(int j=i;j<=n;j++){
			if(c[a[j]]==1){
				b[a[j]]++;
				c[a[j]]=0;
			}
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
        
	return 0;
} 


