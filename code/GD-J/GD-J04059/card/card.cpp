#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int arr[500005]={0};
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	int ans[300005]={0};
	int txt[500005]={0};
	int bb=1;
	for(int z=1;z<=n;z++){
		bool flag[300005]={0};
		for(int i=z;i<=n;i++){
			txt[bb]=arr[i];
			bb++;
			if(flag[i]==1){
				for(int j=bb-1;j>=1;j--){
					flag[txt[j]]=0;
					if(txt[j]==txt[bb]){
						bb=j;
					}
				}
			}
			flag[txt[i]]=1;
		}
		for(int i=1;i<=m;i++){
			if(flag[i]==1){
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
