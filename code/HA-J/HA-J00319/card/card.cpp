#include<bits/stdc++.h>
using namespace std;
int num[500005],sum[500005],k[500005],l[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>num[i];
	}
	for(int i=1;i<=m;i++){
		memset(k,0,sizeof(k));
		for(int j=i;j<=m;j++){
			sum[j]=num[j];
			k[num[j]]++;
			if(k[num[j]]==2){
				for(int h=j-1;;h--){
					if(sum[h]==sum[j]){
						sum[j]=0;
						break;
					}
					sum[h]=0;
				}
				k[num[j]]--;
			}
		}
		for(int j=i;j<=m;j++){
			l[sum[j]]++;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<l[i]<<" ";
	}
}
