#include<bits/stdc++.h>
#define du double
#define ll long long
using namespace std;
const int M=5e5+5;
int dp[3005][5005],ans[3005];
int a[M];
map<int,int>mp;
int main(){
	//std::ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	int n,m;
	cin>>n>>m; 
	bool mx=1;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]<a[i-1])mx=0;
		if(mp[a[i]]==0)mp[a[i]]=i;
	}
	if(mx){//从小到大 
		for(int i=1;i<m;++i){
			cout<<mp[i+1]-mp[i]<<" ";
		}cout<<(n-mp[m]+1);
	}else{
		stack<int>st;
		for(int i=1;i<=n;++i){
			for(int x=1;x<=m;++x)mp[x]=0;
			st.push(0);
			for(int j=i;j<=n;++j){
				if(mp[a[j]]==0){
					st.push(a[j]);
				}else{
					while(!st.empty()){
						if(st.top()==a[j])break;
						mp[st.top()]=0;
						st.pop();
					}
				}mp[a[j]]=1;
			}
			int l=st.size();
			while(!st.empty()){
				ans[st.top()]++;
				st.pop();
			}
		}
		for(int i=1;i<=m;++i)cout<<ans[i]<<" ";
	}
	return 0;
}
