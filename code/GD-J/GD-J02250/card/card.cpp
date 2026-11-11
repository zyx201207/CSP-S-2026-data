#include <bits/stdc++.h>
using namespace std;
long long a[2500005];
int flag[300005];
int cnt[0300005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int lun=1;
	while(lun<=n){
		int zhuo[2500005];
		for(int i=lun-1;i<=n;i++){
			if(flag[a[i]]==0){
				flag[a[i]]=1;
				zhuo[i]=a[i];
			}
			else{
				for(int j=lun-1;j<i;j++){
					if(j==a[i]){
						for(int k=j;k<=i;k++){
							zhuo[k]=0;
						}
					}
				}
			}
			
		}
		for(int i=lun-1;i<=n;i++){
			if(zhuo!=0){
				cnt[i]++;
			} 
		}
	}
	for(int i=0;i<m;i++){
		cout<<cnt[i]; 
	}
	
	return 0;	
}
