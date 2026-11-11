#include <bits/stdc++.h>
#define debug(n) 
using namespace std;

int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	bool have[m];
	int ans[m];
	stack<int> s;
	for(int i=0;i<n;i++){
		cin>>a[i]; 
	}
	for(int ju=1;ju<=n;ju++){
		debug(ju);
		for(int i=ju-1;i<=n-1;i++){
			debug(i);
			if(have[a[i]-1]){
				while(s.top()!=a[i]){
					have[s.top()-1]=false;
					s.pop();
				}
				s.pop();
			}
			have[a[i]-1]=true;
			s.push(a[i]);
			
		}
		for(int i=1;i<=m;i++){
			if(have[i-1]) ans[i-1]++,have[i-1]=false;
		}
		for(int i=0;i<m;i++){
			debug(ans[i]);
		}
	}
	
	for(int i=0;i<m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
