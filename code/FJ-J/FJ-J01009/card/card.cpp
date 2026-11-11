#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int a[101010];
int ans[101010];
int v[1010101]={0};
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int>st;
		memset(v,0,sizeof v);
		for(int j=i;j<=n;j++){
			if(v[a[i]]){
				while(v[a[j]]){
					v[st.top()]=0;
					st.pop();
				}
			}
			st.push(a[j]);
			v[a[j]]=1;
		}
		for(int j=1;j<=n;j++){
			ans[j]+=v[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*










*/
