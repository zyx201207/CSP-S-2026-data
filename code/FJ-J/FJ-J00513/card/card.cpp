#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],ans[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<bool>t(n+1);
		vector<int>l(m+1);
		for(int j=i;j<=n;j++){
			if(l[a[j]]!=0&&t[l[a[j]]]==0){
				for(int k=l[a[j]];k<j;k++){
					t[k]=1;
				}
			}
			l[a[j]]=j;
		}
		for(int j=i;j<=n;j++){
			if(!t[j])ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
	}
	return 0;
}
