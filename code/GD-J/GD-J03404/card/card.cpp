//csp RP++
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans[100005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long wz[100005]={};
		for(int j=i;j<=n;j++){
			if(wz[a[j]]!=0){
				for(int k=i;k<=n;k++){
					if(wz[a[k]]>wz[a[j]]){
						wz[a[k]]=0;
					}
				}
			}
			wz[a[j]]=j;
		}
		for(int j=i;j<=n;j++){
			if(wz[a[j]]!=0){
				ans[a[j]]++;
				wz[a[j]]=0; 
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
