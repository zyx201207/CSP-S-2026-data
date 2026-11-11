#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[114514],num[114514];
queue<int> q;
map<int,bool> mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.ans","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			q.push(a[j]);
			int t=q.front();
			if(mp[t]){
				while(!q.empty()) q.pop();
			}
			q.push(t);
			mp[t]=1;
		}
		for(int i=1;i<=k;i++){
			int t=q.front();
			q.pop();
			num[t]++;
		}
	}
	for(int i=1;i<=k;i++){
		cout<<num[i]<<' ';
	}
	return 0;
}
