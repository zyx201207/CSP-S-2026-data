#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,m,a[maxn],cnt[maxn];
int lg[maxn];
stack<int>w[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		w[i].push(0);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(w[a[j]].top()>0){
				for(int k=w[a[j]].top();k<=j-1;k++){
					lg[a[k]]--;
					w[a[k]].pop();
				}
			}
			lg[a[j]]++;
			w[a[j]].push(j);
		}
		for(int j=1;j<=m;j++){
			cnt[j]+=lg[j];
			lg[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
