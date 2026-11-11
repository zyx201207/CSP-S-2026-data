#include<bits/stdc++.h>
using namespace std;
int n,k,c,T;
int check(int num,vector<int> a[],int m){
	int flag[2000005];
	memset(flag,0,sizeof(flag));
	queue<pair<int,int>> q;
	int cnt=1,r=0;
	q.push({1,0});
	while(!q.empty()){

		int f=q.front().first,g=q.front().second;
		q.pop();
		flag[f]=1;
		
		for(int u:a[f]){
			if(flag[u]) continue;
			q.push({u,g+1});
			r=1;
		}
		if((!r&&num<g)||g>num*2){
			cnt++;
		}
	}
	return cnt<=m;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		vector<int> q[1000005];
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			q[u].push_back(v);
			q[v].push_back(u);
		}
		int l=1,r=2e6;
		while(l<r){
			int mid=(l+r)/2;
			if(check(mid,q,k)){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		cout<<l<<'\n';
	}
	return 0;
}
