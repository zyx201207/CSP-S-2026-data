#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
int n,m;
int a[N];
int vis[N];
int cnt[N];
int s[N];
int din[N];
queue<int>q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[a[i]]=i;
		cnt[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		s[i]=a[vis[i]+1];
		din[a[vis[i]+1]]++;
	}
	for(int i=1;i<=m;i++){
		if(din[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		int v=s[x];
		cnt[v]+=cnt[x];
		din[v]--;
		if(din[v]==0){
			q.push(v);
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i];
		if(i!=m)cout<<" ";
	}
	return 0;
}
