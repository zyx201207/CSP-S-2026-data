#include<bits/stdc++.h>
using namespace std;
int m,n,a[500010],b[500010],k,ans[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i ++)cin>>a[i];
	for(int i = 1;i <= n;i ++){
		k = 0;
		for(int j = i;j <= n;j ++){
			for(int p = 1;p <= k;p ++){
				if(b[p] == a[j]){
					k = p - 1;
				}
				
			}
			b[++k] = a[j];
//			for(int p = 1;p <= k;p ++)cout<<b[p];
//			cout<<endl;
		}
		for(int j = 1;j <= m;j ++){
			for(int p = 1;p <= k;p ++){
				//cout<<b[p]<<' ';
				if(b[p] == j){
					ans[j] ++ ;
				}
			}
			//cout<<endl;
		}
	}
	for(int i = 1;i <= m; i++){
		cout<<ans[i]<<' ';
	}
}
