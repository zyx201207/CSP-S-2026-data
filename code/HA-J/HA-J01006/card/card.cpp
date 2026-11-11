#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m,ans[500050];
	deque<int> a;
	cin>>n>>m;
	
	for(int i=0;i<=n+15;i++){
		
		ans[i]=0;
		
	}
	for(int i=1;i<=n;i++){
		
		int x;
		cin>>x;
		a.push_back(x);
		
		ans[x]= ( ans[x] + 1 ) ;
		
	}
	
	bool f=true;
	for(int i=1;i<=n;i++){
		
		cout<<ans[i];
		
		ans[a.front()]--;
		a.pop_front();
		
	}
	return 0;
}