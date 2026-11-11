#include<bits/stdc++.h>
using namespace std;
int n,m,a[5],s[3];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		stack<int> st;
		int d[3];
		for(int j=i;j<n;j++){
			while(d[a[i]]){
				d[st.top()]--;
				st.pop();
			}
			st.push(a[i]);
			d[a[i]]++;
		}																 
		while(st.size()){
			s[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i];
	}
	return 0;
}
