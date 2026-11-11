#include<bits/stdc++.h>
using namespace std;

int n,m;
int card[500010];
int ct[300010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	vector<vector<int> >id;
	for(int i=1;i<=m;i++){
		id.push_back({0});
	}
	for(int i=1;i<=n;i++){
		cin>>card[i];
		id[card[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		int x=card[i];
		int v=i;
		while(v<=n){
			ct[x]++;
			if(v==n)break;
			v=id[x][id[x].size()-1]+1;
			x=card[v];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ct[i]<<" ";
	}
	return 0;
} 
