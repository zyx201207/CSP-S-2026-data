#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m;
LL a[500010];
stack <LL> st;
bool vis[300010]={0};
map<LL,LL> cal;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cal[a[i]]=0;
	}
	LL q=n,b=1;
	while(q--){
		memset(vis,0,sizeof(vis));
		for(int i=b;i<=n;i++){
			if(!vis[a[i]]){
				st.push(a[i]);
				vis[a[i]]=1;
			}else{
				while(st.top()!=a[i]){
					st.pop();
				}
			}
		}
		while(!st.empty()){
			cal[st.top()]++;
			st.pop();
		}
		b++;
	}
	for(auto y:cal){
		cout<<y.second<<" ";
	}
	return 0;
}
