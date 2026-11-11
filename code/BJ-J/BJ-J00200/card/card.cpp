#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[300005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int final_sum[300005]={0};
	for(int i=1;i<=m;i++){
		int now[300005],num[300005],num_cou[300005];
		for(int j=1;j<=m-i+1;j++){
			now[j]=a[j+i-1];
			num[now[j]]++;
			if(num[now[j]]==2) {
				for(int z=num_cou[now[j]];z<=j-1;z++){
					num[now[z]]--;
					num_cou[now[z]]=0;
				}
			}else{
				num_cou[now[j]]=j;
			}
		}
		for(int z=1;z<=m;z++){
			final_sum[z]+=num[z];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<final_sum[i]<<" ";
	}
	return 0;
}
