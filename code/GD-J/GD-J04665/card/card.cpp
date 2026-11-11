#include<bits/stdc++.h>
#define ll long long
//unsigned long long
//priority_queue<int,vector<int>,greater<int>>;
using namespace std;
int n,m,a[500005],id[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		id[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		ans[a[i]]++;
		int j=id[a[i]]+1;
		while(j<=n){
			ans[a[j]]++;
			j=id[a[j]]+1;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}

