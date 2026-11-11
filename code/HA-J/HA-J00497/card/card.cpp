//card
#include <bits/stdc++.h>
using namespace std;

int n,m,a[500005];
map <int,bool> mp;
map <int,int> ans;
stack <int> st;

void f(int k){
	if (mp[k]){
		while (st.top() != k){
			mp[st.top()] = 0;
			st.pop();
		}
		st.pop();
		mp[k] = 0;
	}
	st.push(k);
	mp[k] = 1;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n;i ++){
		cin>>a[i];
	}
	for (int i = 1;i <= n;i ++){
		mp.clear();
		for (int j = i;j <= n;j ++){
			f(a[j]);
		}
		while (st.size()){
			ans[st.top()] ++;
			st.pop();
		}
	}
	for (int i = 1;i <= m;i ++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
