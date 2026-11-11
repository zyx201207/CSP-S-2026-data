#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],ans[300005];
vector<int>v[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		v[a[i]].push_back(i);
	}
	for(int i=0;i<n;i++){
		int j=i;
		while(j<n){
			ans[a[j]]++;
			j=v[a[j]].back();
			j++;
		}
		ans[a[j]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
