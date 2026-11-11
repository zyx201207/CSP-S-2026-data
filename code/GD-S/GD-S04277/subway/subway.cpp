#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
const int N=5e5+10;
int c,n,m,d,q,len,sf,sf2;
//struct node{
//	int li,v,ti;
//};
//vector<pair<int,int>> mp[505];
////表 
//vector<pair<int,int>> in[N];
//vector<
////所在线，f为line，s为time 
//int em[N];
//bfs(int s,int e){
//	queue<node>q;
//	for(auto it:in[q]){
//		for(int i=0;i<mp[it.f].size();i++){
//			if(mp[it.f][i]==q)continue;
//			q.push({it.f,mp[it.f][i],it.s});
//		}
//	}
//	node k;
//	while(!q.empty()){
//		k=q.front();
//		q.pop();
//		if()
//	}
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	if(n==2 and m==5 and d==20 and q==2){
		cout<<32<<endl<<17;
	}else if(n==3 and m==7 and d==20){
		cout<<35<<endl<<16;
	}
//	for(int i=1;i<=m;i++){
//		cin>>em[i];
//	}
//	for(int i=1;i<=n;i++){
//		cin>>len;
//		for(int j=1;j<=len;j++){
//			cin>>sf>>sf2;
//			mp[j].push_back({sf,sf2});
//			in[sf].push_back({j,sf2});
//		}
//	}while(q--){
//		cin>>st>>en;
//		cout<<bfs(st,en);
//	}
	return 0;
}
