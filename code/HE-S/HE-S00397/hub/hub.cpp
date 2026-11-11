#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,k,c,f[N],ans;
vector<int>e[N];
void dp(int x,int fa){
	priority_queue<int>q;
	for(int i=0;i<e[x].size();i++){
		if(e[x][i]!=fa){
			dp(e[x][i],x);
			q.push(f[e[x][i]]);
		}
	}
	if(q.size()){
		f[x]+=q.top()+1;
		ans=max(ans,f[x]);
		if(q.size()){
			ans=max(ans,f[x]+q.top()+1);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=0;
		for(int i=1;i<=n;i++){
			while(e[i].size())e[i].pop_back();
			f[i]=0;
		}
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int m=n/2,l=m-1;
		if(n==k)cout<<0<<"\n";
		else if(k>=m)cout<<1<<"\n";
		else if(k==2)cout<<l/2+l%2+1<<"\n";
		else if(m%2==1)cout<<round(round((l-(k-3))/2.0)/2.00)+1<<"\n";
		else cout<<((l-(k-4))/2+(l-(k-4))%2)/2+2<<"\n";
	}
	return 0;
}
//Ã»¾ÈÁË£¬
//ÄÜÄÃ 2=Âð£¿
//total=162pts
//int uid=1337006;
//keyword:
/*
luogu
//freopen(
,"r",stdout);
,"w",stdin);
hub6.in
hub.cpp
*/ 
