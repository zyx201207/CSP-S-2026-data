#include<bits/stdc++.h>
using namespace std;
const int mx=5e5+10,mx2=3e5+10;
int n,m;
int a[mx];
int ans[mx2];
void game(int l){//l-n
	map<int,bool> has;
	stack<int> st;
	for(int i=l;i<=n;i++){
		if(!has.count(a[i])){
			has[a[i]]=1;
			st.push(a[i]);
		}else{
			while(st.top()!=a[i]){
				has.erase(st.top());
				st.pop();
			}
			has.erase(a[i]);
			st.pop();
			
			has[a[i]]=1;
			st.push(a[i]);
		}
	}
	while(!st.empty()){
		ans[st.top()]++;
		st.pop();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) game(i);
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	cout<<'\n';
	return 0;
}
//4 3
//1 2 1 3
