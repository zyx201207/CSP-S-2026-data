#include<bits/stdc++.h>
using namespace std;
set<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long i;
	long long s=1;
	for(i=1;i<=m;i++){
		int x;
		cin>>x;
		st.insert(x);
	}
	for(i=0;i<st.size();i++){
		cout<<s<<" ";
		s*=(i+2);
	}
	return 0;
} 
