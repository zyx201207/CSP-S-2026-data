#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int bjz[5005],bjy[5005];
int cf[5005];
int cs[5005];
int bj[5005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			bj[j]=0;
			cf[j]=0;
		}
		for (int j=i;j<=n;j++){
			for (int k=i;k<j;k++){
				if(j==n){
					//cout<<k<<" "<<bj[k]<<" "<<a[k]<<" ";
				}
				if(bj[k]==0&&a[k]==a[j]){
					for (int l=k;l<j;l++){
						bj[l]=1;
					}
					break;
				}
			}
		}
		//cout<<"\n";
		for (int j=i;j<=n;j++){
			if(bj[j]==0){
				cf[a[j]]=1;
			}
			//cout<<bj[j]<<" ";
		}
		//cout<<"\n";
		for (int j=1;j<=m;j++){
			if(cf[j]==1){
				cs[j]++;
			}
		}
	}
	for (int i=1;i<=m;i++){
		cout<<cs[i]<<" ";
	}
	return 0;
} 
