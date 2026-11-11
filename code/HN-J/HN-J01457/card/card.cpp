#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n,m,a[N],ans[N],vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int>s;
		for(int j=1;j<=m;j++)vis[j]=0;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==1){
				while(s.top()!=a[j])vis[s.top()]=0,s.pop();
			}else{
				vis[a[j]]=1;
				s.push(a[j]);
			}
		}
		for(int j=1;j<=m;j++){
			if(vis[j]==1)ans[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";

	return 0;
}
//预计过 1~12 测试点 
//预计得分 48 
