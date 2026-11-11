#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum[1000001]={0},bj[1000001]={0};
	int a[3000005];
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int sum[1000001]={0},bj[1000001]={0};
		int zz[300005],o=0;
		for(int j=i;j<=m;j++){
			int qq=0;
			for(int k=j;k>=i;k--){
				if(zz[k]==a[j]){
					for(int l=k;l<=j;l++){
						zz[l]=0;
						o--;
					} 
					qq=1;
					break;		
				}
			}
			zz[o]=a[j];
			o++;
		}
		for(int j=1;j<=o;j++){
			if(bj[zz[j]]==0){
				sum[zz[j]]+=1;
				bj[zz[j]]=1;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<sum[i]<<" ";
	return 0;
}

