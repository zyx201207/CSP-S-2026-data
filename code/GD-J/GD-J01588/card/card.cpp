#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,a[N],ans[N],m;
bool inst[N];
stack<int>st;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(inst[a[j]]){
				while(st.top()!=a[j]){
					inst[st.top()]=0;
					st.pop();
				}
			}
			else{
				st.push(a[j]);
				inst[a[j]]=1;
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			inst[st.top()]=0;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
//10 3 3 1 2 1 3 2 3 1 2 1
