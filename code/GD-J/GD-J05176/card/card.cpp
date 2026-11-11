#include<bits/stdc++.h>
using namespace std;
int a[500005],cnt[500005],stk[500005],head;
vector<int> tmp[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int head=0;
		for(int j=1;j<=m;j++)tmp[j].clear();
		for(int j=i;j<=n;j++){
			if(tmp[a[j]].size()){
				head=tmp[a[j]].back()-1;
				tmp[a[j]].pop_back();
			}
			stk[++head]=a[j];
			tmp[a[j]].push_back(head);
		}
		for(int j=1;j<=head;j++){
				cnt[stk[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
