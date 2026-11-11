#include<bits/stdc++.h>
using namespace std;
#define int long long
stack<int> st;
map<int,int> mp;
int a[500005];
int t[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=n;k++){
		mp.clear();
		for(int i=k;i<=n;i++){
			if(mp.count(a[i])==1){
				while(st.size()&&st.top()!=a[i]){
					mp.erase(st.top());
					st.pop();
				}
				mp.erase(st.top());
				st.pop();
			}
			st.push(a[i]);
			mp[a[i]]=1;
		}
		while(st.size()){
//			cout<<st.top()<<"  ";
			t[st.top()]++;
			st.pop();
		}
//		cout<<"\n------------------------\n";
	} 
	cout<<t[1];
	for(int i=2;i<=m;i++) cout<<" "<<t[i];
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
