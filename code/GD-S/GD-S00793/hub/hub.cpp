#include<bits/stdc++.h>
using namespace std;
int fa[1000005];
struct node{
	int u,v,w;
	void input(){
		cin>>u>>v>>w;
	}
}a[1000005];
bool cmp(node o,node p){
	return o.w<p.w;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,cnt=0;
	cin>>c>>t;
	while(t--){
		cnt++;
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<n;i++)a[i].input();
		sort(a+1,a+n+1,cmp);
		cout<<cnt<<endl;
	}
	return 0;
} 
//1.生成一个k个点的最小生成树(kruskal) 
//2.求割边
//3.分类讨论是去掉割边后答案更优还是保留割边更优 
