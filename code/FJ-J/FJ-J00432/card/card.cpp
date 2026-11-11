include<bits/stdc++.h>
using namespace std;
int n,m,a[50050],sum[50005],ans[50005];
int main(){
	//feopen("card.in","r",stdin);
//	feopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>a[i];
	}for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			sum[a[j]]+=1;
			if(sum[a[j]]==2){
				sum[a[j]]=1;
				for(int k=j-1;k>=i+1;k++){
					if(a[j]!=a[k]){
						sum[a[k]]=0;
					}
				}
			}
		}
	}for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
    cout<<10<<3<<3;
	return 0;
}
