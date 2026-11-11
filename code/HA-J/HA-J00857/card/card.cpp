#include <bits/stdc++.h>
using namespace std;
stack <int> stk;
int pos[100005],mk[1000005],a[100005];
int main () {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!pos[a[j]]){
				pos[a[j]]=j;
				stk.push(a[j]);
			}else {
				while(stk.top()!=a[j]){
					stk.pop();
				} 
				pos[a[j]]=j;
			}
		}
	}
	while(!stk.empty()){
		mk[stk.top()]=1;
		stk.pop();
	}
	for(int i=1;i<=m;i++){
		cout<<mk[i];
	}
	return 0;
}
