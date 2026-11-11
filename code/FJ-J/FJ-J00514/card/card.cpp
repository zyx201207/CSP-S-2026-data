#include<bits/stdc++.h>
using namespace std;
int a[500001],b[500001],f[300001],c[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m,max;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int ff=1;ff<=max;ff++){
			f[ff]=0;
		}
		max=0;
		for(int j=i;j<=n;j++){
			b[j]=a[j];
			for(int k=i;k<j;k++){
				if(b[k]==b[j]){
					for(int p=k;p<j;p++){
						b[p]=0;
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(f[b[j]]==0){
				c[b[j]]++;
				f[b[j]]=1;
				if(b[j]>=max) max=b[j];
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
