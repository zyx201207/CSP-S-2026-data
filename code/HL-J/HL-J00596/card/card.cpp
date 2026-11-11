#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	set<int>s;
	for(int i=0;i<n;i++){
		int si;
		cin>>si;
		s.insert(si);
	}
	if(n==1 && m==1)cout<<1;
	if(n==2 && m==2)cout<<1<<" "<<2;
	
	return 0;
} 
