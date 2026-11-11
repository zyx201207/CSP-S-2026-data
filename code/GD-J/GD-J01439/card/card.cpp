#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,m,a[N];
int js[N];
int s[N]={0};
bool vis[N]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		memset(s,0,sizeof(s));
		memset(vis,false,sizeof(vis));
		stack<int> sk;
		for(int j=i;j<=n;j++){
			if(s[a[j]]){
				int p=sk.top();
				while(!sk.empty()&&p!=a[j]){
					sk.pop();
					p=sk.top();
				}
			}
			else{
				sk.push(a[j]);
			}
			s[a[j]]=j;
		}
		while(!sk.empty()){
			if(!vis[sk.top()]) js[sk.top()]++;
			vis[sk.top()]=true;
			sk.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<js[i]<<' ';
	}

	return 0;
}
