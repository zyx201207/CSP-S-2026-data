#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
void game(int num){
	int ma[300005];
	memset(ma,0,sizeof ma);
	stack<int> t;
	for(int i=num;i<=n;i++){
		if(ma[a[i]]==0){
			ma[a[i]]=1;
			t.push(a[i]);
			continue;
		}
		while(t.top()!=a[i]) t.pop();
	}
	while(!t.empty()){
		ans[t.top()]++;
		t.pop();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		game(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
