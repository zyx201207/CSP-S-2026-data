#include<bits/stdc++.h>
using namespace std;
set<int> q;
signed main(){
	int a;
	int c;
	cin>>a>>c;
	for(int i=1;i<=a;i++){
		int x;
		cin>>x;
		q.insert(x);
	}
	for(int i=1;i<=q.size();i++){
		cout<<q.first();
		q.pop();
	}
	return 0;
}
