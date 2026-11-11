#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans[500010],maxx[500010];
//vector<vector<int>> w(500010);
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxx[a[i]]=i;
//		w[a[i]].push_back(i);
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
//			cout<<j<<" ";
			ans[a[j]]+=1;
			j=maxx[a[j]];
//			cout<<j<<" ";
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
