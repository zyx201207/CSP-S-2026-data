#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int c[N],t[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	set<int> st;
	for(int i=1;i<=n;i++){
		stack<int> sk;
		for(int j=i;j<=n;j++){
			if(!st.count(c[j]))
				sk.push(c[j]),st.insert(c[j]);
			else{
				while(sk.top()!=c[j]){
					st.erase(sk.top());
					sk.pop();
				}
			}
		}
		while(!sk.empty()){
			t[sk.top()]++;
			sk.pop();
		}
		st.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<' ';
	}
	return 0;
}
