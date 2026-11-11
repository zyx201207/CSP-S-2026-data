#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
stack<int>st;
bool ins[N];
int ans[N];
bool subA=1;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1] && i>1)subA=0;
	}
	if(subA){
		for(int i=1;i<=n;i++){
			ans[a[i]]=i;
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<" "; 
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(ins[a[j]]==0){
				ins[a[j]]=1;
				st.push(a[j]);
			}
			else {
				while(st.top()!=a[j]){
					ins[st.top()]=0;
					st.pop();
				}
			}
		}
		while(st.size()){
			ins[st.top()]=0;
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/

