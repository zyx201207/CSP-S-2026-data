#include<bits/stdc++.h>
using namespace std;
int a[500010],cnt[300010];
int vis[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
		if(a[i]<a[i-1]&&n!=1){
			f=0;
		}
	}
	if(f){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(a[j]==i){
					cout<<j+cnt[a[j]]-1<<endl;
					break;
				}
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=i;k<=j;k++){
				if(vis[k]&&a[k]==a[j]){
					for(int l=1;l<=j;l++){
						if(vis[l]>vis[k])vis[l]=0,cnt[vis[l]]--;
					}
					vis[k]=0;
				}
			}
			vis[a[j]]++;
			cnt[a[j]]++;
		} 
	} 
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<endl;
	}
	return 0;
}

