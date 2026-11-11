#include<bits/stdc++.h>
using namespace std;
int we[1000000],n,m,un,a[1000000],ans[1000000],full[1000000],pick,final[1000000];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int s=1;s<=n;s++){
			full[s]=0;
			ans[s]=0;
		}
		for(int j=i,k=1;j<=n;j++,k++){
			if(full[a[j]]==0){
				ans[k]=a[j];
				full[a[j]]=k;
			}
			else{
				un=full[a[j]];
				for(int y=full[a[j]];y<=k;y++){
					pick=ans[y];
					ans[y]=0;
					full[pick]=0;
				}
				ans[un]=a[j];
				k=un;
			}
			
		}
		for(int o=1;o<=n;o++){
			final[ans[o]]=1;
		}
		for(int o=1;o<=n;o++){
			we[o]+=final[o];
		}
		for(int o=1;o<=n;o++){
			final[o]=0;
		}
		
	}
	for(int p=1;p<=m;p++){
		cout<<we[p]<<" ";
	}

} 
