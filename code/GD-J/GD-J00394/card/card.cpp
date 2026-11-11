#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
map<int,int>mp;
stack<int>st;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(mp[a[j]]>0){
				while(!st.empty()&&st.top()!=a[j]){
					int x=st.top();
					mp[x]--;
					st.pop();
				}
			}
			else{
				st.push(a[j]);
				mp[a[j]]++;
			}	
		}
		while(!st.empty()) st.pop();
	}
	for(int i=1;i<=m;i++) cout<<mp[i]<<" ";
	return 0;
}
