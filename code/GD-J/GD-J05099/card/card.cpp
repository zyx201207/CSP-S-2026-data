#include<bits/stdc++.h>
using namespace std;
int a[500005];
int n,m;
int tong[300005];
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		//b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		memset(tong,0,sizeof(tong));
		for(int j=i;j<=n;j++){
			if(tong[a[j]]){
				for(int k=tong[a[j]];k<=j;k++){
					tong[a[k]]=0;
				}
			}
			tong[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(tong[j]){
				//cout <<j<<" ";
				ans[j]++;
			}
		}
		//cout <<'\n';
	}
	for(int i=1;i<=m;i++){
		cout << ans[i]<<' ';
	}
	return 0;
}

