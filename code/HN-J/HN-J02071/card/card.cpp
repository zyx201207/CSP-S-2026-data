#include<bits/stdc++.h>
using namespace std;
int ta[500005],n,m,a[500005],cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ta[j]=a[j];
			int k=j;
			while(k--){
				if(a[j]==ta[k]){
					for(int l=j-1;l>=k;l--){
						ta[l]=0;
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
		cnt[ta[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	//ys uid:230118859
	return 0;
}
