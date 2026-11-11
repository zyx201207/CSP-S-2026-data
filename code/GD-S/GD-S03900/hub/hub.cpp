#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int>>q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,m;
		cin>>n>>m;
		int u,v;	
		for(int i=1;i<n;i++){
			cin>>u>>v;	
		}
		cout<<m-1<<endl;
	}
}
