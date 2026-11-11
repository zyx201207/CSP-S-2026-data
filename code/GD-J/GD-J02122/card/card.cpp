#include<bits/stdc++.h>
using namespace std;
int card[10005]={0};
int zm[10005]={0};
int ans[10005]={0};
bool check(int x,int k){
	for(int i=1;i<=k;i++){
		if(zm[i]==x){
			return 0;
		}
	}
	return 1;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>card[i];
		
	}
	int js=n;
	int i=1;int k=1;
	while(js){
		for(int j=i;j<=n;j++){
			if(check(card[j],k)){
				zm[k]=card[j];
				k++;
			}
			else{
			    for(int l=1;l<=k;l++){
		            if(zm[l]==card[j]){
			            
			            for(int o=l+1;o<=k;o++){
			            	zm[o]=0;
						}
			            k=k-l+1;
		            }
               	}		
			}
		}
		for(int t=1;t<=n;t++){
			for(int r=1;r<=m;r++){
				if(zm[t]==r){
					ans[r]++;
				}
			}
		}
		i++;k=i;js--;
		for(int w=0;w<=10005;w++){
			zm[w]=0;
		}
	}
	for(int q=1;q<=m;q++){
		cout<<ans[q]<<" ";
	}
}
