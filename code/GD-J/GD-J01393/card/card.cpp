#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
#define ll long long 
ll san[N],zh[N],ans[N];
int fea[N],fa[N];
void rel(int cl){
	if(cl==0)return ;
	//cout<<cl<<" "<<zh[cl]<<" "<<san[cl]<<"\n";
	zh[fea[cl]]+=(zh[cl]);
	san[fea[cl]]+=(zh[cl]);
	zh[cl]=0;
	rel(fea[cl]);
}
int n,m,c[N],vis[N],vis2[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=n;i>=1;i--){
		if(vis[c[i]]==0){
			fea[c[i]]=c[i+1];
			fa[c[i+1]]=c[i];
			vis[c[i]]=1;
		}
		zh[c[i]]++;
		san[c[i]]++;
	}
	for(int i=1;i<=m;i++){
		if(fa[i]==0){
			rel(i);
		}
	}
	for(int i=1;i<=m;i++){
		cout<<san[i]<<" ";
	}
}
/*
4 3
1 2 1 3
*/
