#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	int n,m,s[100005],dp[100005],d=1,cnt[100005]={0};
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int k=s[j];
//			int pos=lower_bound(dp+1,dp+d+1+1,k);
			int pos=-1;
			for(int z=1;z<=d;z++){
				if(dp[z]>=k){
					pos=z;
					break;
				}
			}
			if (pos==-1){
				dp[d] = k;
				d++;
			}
			else{
				d-=d-pos+1;
				dp[d]=k;
				d++;
			}

		}
//		int pos=lower_bound(dp+1,dp+d+1+1,s[i]);
		int pos=-1;
		for(int z=1;z<=d;z++){
			if(dp[z]>=s[i]){
				pos=z;
				break;
			}
		}
		if(pos!=-1){
			cnt[s[i]]++;
		}

		d=1;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}

	return 0;
}
