#include<bits/stdc++.h>
using namespace std;


int a[500005],r=1,n,m,ans,qwq[500005],temp[500005];
bool f[300005];



int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){//n games
		
		for(int j=i;j<=n;j++){
			if(f[a[j]]==1){
				for(int k=1;k<=r;k++){
					if(temp[k]==a[j]){
						
						for(int l=k;l<=r;l++){
							f[a[l]]=0;
						}
						r=k-1;
						break;
					}
				}
			}
			else{
				temp[r]=a[j];
				r++;
				f[a[j]]=1;
			}
		                                      //	cout<<temp [r]<<"   ";
		}
		
		
		for(int awa=1;awa<=m;awa++){
			for(int j=1;j<=r;j++){
				if(temp[j]==awa){
					qwq[awa]++;
				}
				
			}
		}
		for(int j=1;j<=r;j++){
			temp[j]=0;
			f[j]=0;
		}
		
	}
	
	for(int i=1;i<=m;i++){
		cout<<qwq[i]<<" ";
	}
	return 0;
}


