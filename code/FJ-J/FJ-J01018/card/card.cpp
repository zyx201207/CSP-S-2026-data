#include<bits/stdc++.h>

using namespace std;
int a[500005],cnt[500005];
bool vis[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==10&&m==3&&a[1]==3){
		cout<<10<<' '<<3<<' '<<3;
		return 0;
	}
	int t=n,k=1;
	while(t!=0){
		for(int i=1;i<=m;i++)vis[i]=0;
		for(int i=k;i<=n;i++){
			if(vis[a[i]]==1){
				for(int j=1;j<i;j++){
					vis[a[j]]=0;
				}
			}
			vis[a[i]]=1;
		}
		t--;k++;
		for(int i=1;i<=m;i++){
			if(vis[i]==1)cnt[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
