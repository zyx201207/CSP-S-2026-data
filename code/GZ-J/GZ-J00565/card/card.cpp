//GZ-J00565 ¡∫∫È»Ò 
#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e5+5;
void solve(){
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<int>ans(m+1,0);
	for(int i=1;i<=n;i++){
		stack<int>st;
		vector<bool>v(m+1,0);
		for(int j=i;j<=n;j++){
			st.push(a[j]);
			if(v[a[j]]){
				st.pop();
				while(!st.empty() && st.top()!=a[j]){
					v[st.top()]=0;
					st.pop();
				}
			}
			v[a[j]]=1;
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
