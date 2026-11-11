#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010],f[300010],s[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n<=5000){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			memset(f,0,sizeof(f));
			int r=0;
			for(int j=i;j<=n;j++){
				if(!f[a[j]]){
					ans[a[j]]++;
					f[a[j]]++;
					s[++r]=a[j];
				}else{
					while(a[r]!=a[j]){
						f[a[r]]--;
						ans[a[r]]--;
						r--;
					}
				}
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans[a[i]]+=i;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
