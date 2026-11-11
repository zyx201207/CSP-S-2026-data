#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
bool f[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int t=1;t<=n;t++){
		for(int i=t;i<=n;i++){
			if(f[a[i]]==1){
				for(int j=a[i];j<=n;j++){
					f[j]=0;
				}
			}
			else{
				f[a[i]]=1;
			}
		}
		for(int i=1;i<=n;i++){
			if(f[i]){
				ans[i]++;
			}
		}
		for(int i=1;i<=m;i++){
			f[i]=0;
		}
	}
	for(int i=1;i<=n;i++){
		cout << ans[i];
	}
	
	return 0;
}
