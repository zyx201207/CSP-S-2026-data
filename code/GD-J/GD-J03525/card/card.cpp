#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int>ar(n+1),ans(m+1);
	for(int i=1;i<=n;i++){
		cin>>ar[i];
	}
	for(int i=1;i<=n;i++){
		vector<bool>f(n,0);
		for(int j=i;j<=n;j++){
			if(f[ar[j]]==0){
				f[ar[j]]=1;
			}
			else{
				for(int k=j-1;k>=i;k--){
					f[ar[k]]=0;
				}
				f[ar[i]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(f[j]==1)ans[j]++;
		}
	}
	for(int j=1;j<=m;j++){
		cout<<ans[j]<<' ';
	}
	return 0;
}
