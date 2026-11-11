#include<bits/stdc++.h>
using namespace std;
int n,m;
int num[200005];
int tong[300005];
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		tong[num[i]]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans[num[j]]++;
			if(tong[num[j]]-1>0){
				int k=j+1;
				for(int l=1;l<tong[num[j]];k++){
					if(num[k]==num[j]){
						l++;
					}
				}
				j=k-1;
			}
		}
		tong[num[i]]--;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
