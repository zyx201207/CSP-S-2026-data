#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,M=3e5+10;
int n,m,a[N],ans[M];
bool b[M];
stack<int>stk;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(b,false,sizeof(b));
		for(int j=i;j<=n;j++){
			if(!b[a[j]]){
				stk.push(a[j]);
				b[a[j]]=true;
			}
			else{
				while(stk.top()!=a[j]){
					b[stk.top()]=false;
					stk.pop();
				}
			}
		}
		while(!stk.empty()){
			ans[stk.top()]++;
			stk.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
