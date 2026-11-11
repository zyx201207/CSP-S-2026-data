#include<bits/stdc++.h>
using namespace std;
long long card[500005];
long long table[500005];
bool is[300005];
long long cnt[300005];
long long location[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(is,0,sizeof(is));
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>card[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!is[j]){
				table[j]=card[j];
				is[j]=1;
				location[card[j]]=j;
			}else if(is[j]==0){
				for(int k=location[card[j]];k<=j;k++){
					table[k]=0;
				}
				table[j]=card[j];
				is[j]=0;
			}
		}
		for(int i=1;i<=sizeof(table);i++){
			if(table[i]>0){
				cnt[i]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<cnt[i];
	}
	return 0;
}
