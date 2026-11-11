#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],nxt[N],cnt[N],tot[N],ans[N];
vector<int>pos[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tot[a[i]]++;
		if(i>1&&a[i]<a[i-1]) f=0;
		pos[a[i]].push_back(i);
	}
	//A
	if(f){
		for(int i=1;i<=m;i++){
			tot[i]+=tot[i-1];
			cout<<tot[i]<<' ';
		}
		cout<<'\n';
		return 0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<pos[i].size()-1;j++){
			nxt[pos[i][j]]=pos[i][j+1];
		}
	}
	for(int i=1;i<=n;i++){
		int p=i;
		while(p<=n){
			if(!nxt[p]){
				cnt[a[p]]++;
				p++;
			}
			else p=nxt[p];
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	cout<<'\n';
	return 0;
}