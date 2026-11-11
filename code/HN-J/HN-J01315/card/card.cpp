#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],q[500005],ans[300005];
vector<int>mp[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i]){
			flag=1;
		}
	}
	if(!flag){
		for(int i=1;i<=n;i++){
			ans[a[i]]++,ans[m+1]--;
		}
		for(int i=1;i<=m;i++){
			ans[i]+=ans[i-1];
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int len=0;
		for(int j=i;j<=n;j++){
			if(mp[a[j]].empty()){
				mp[a[j]].push_back(++len);
				q[len]=a[j];
			}else{
				int t=len;
				for(int k=mp[a[j]][0];k<=t;k++){
					mp[q[k]].pop_back(),len--;
				}
				mp[a[j]].push_back(++len);
				q[len]=a[j];
			}
		}
		for(int j=1;j<=len;j++){
			ans[q[j]]++;
			mp[q[j]].clear();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
