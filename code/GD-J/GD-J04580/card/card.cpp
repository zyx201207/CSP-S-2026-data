#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int pai[n];
	int zhm[n];
	for(int i=0;i<n;i++){
		cin>>pai[i];
	}
	int jpq[m+1],p=0,ans[m+1];
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(jpq[pai[j]]==0){
				zhm[p]=pai[j];
				p++;
			}
			else{
				for(int k=0;k<p;k++){
					zhm[k]=0;
				}
				for(int k=1;k<=m;k++){
					jpq[k]=0;
				}
				zhm[0]=pai[j];
			}
			jpq[pai[j]]++;
		}
		for(int j=0;j<n;j++){
			if(zhm[j]==0)
				break;
			ans[zhm[j]]++;
		}
	}
	for(int i=1;i<m+1;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
