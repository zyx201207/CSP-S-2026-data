//CSP-J 3-and
#include<bits/stdc++.h>
using namespace std;
int n,m;
int trie[200005][2];
int cnt[200005][2];
int c;
void insert(int num){
	int now=0;
	for(int i=30;i>=0;i--){
		bool s=(num>>i)&1;
		if(trie[now][s]==0){
			trie[now][s]=++c;
		}
		cnt[now][s]++;
		now=trie[now][s];
	}
	cnt[now][0]++;
}
vector<int>v;
void recurse(int now,int num,int dep){
	if(dep<0){
		for(int i=1;i<=cnt[now][0];i++)v.push_back(num);
		return;
	}
	if(trie[now][1]){
		recurse(trie[now][1],num+(1<<dep),dep-1);
	}
	if(trie[now][0]){
		recurse(trie[now][0],num,dep-1);
	}
}
int a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		insert(a[i]);
	}
	recurse(0,0,30);
	int ans=v[0];
	for(int i=0;i<m;i++){
		ans&=v[i];
	}
	cout<<ans;
	return 0;
}
