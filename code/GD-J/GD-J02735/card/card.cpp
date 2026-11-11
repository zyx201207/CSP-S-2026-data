#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1,0),ans(m+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<int> f(n+1,1),cnt(m+1,0);
		for(int j=i;j<=n;j++){
			cnt[a[j]]++;
			int id=j,x=a[j];
			for(int k=j-1;k>=i;k--){
				if(a[k]==x){
					id=k;
				}
			}
			for(int k=id;k<j;k++){
				if(f[a[k]]){
					cnt[k]--;
					f[k]=0;
				}
			}
		}
		for(int j=1;j<=m;j++){
			ans[j]+=(cnt[j]>=1);
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
