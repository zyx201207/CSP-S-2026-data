//GZ-J00365 ºî¶÷Í® 
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,m;
int a[N],cnt[N];
set<int> s; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++){
		s.insert(a[i]);
	}
	for(auto e:s){
		cout<<e<<" "; 
	}
	return 0;
}
