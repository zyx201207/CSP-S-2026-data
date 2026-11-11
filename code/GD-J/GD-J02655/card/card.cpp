#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500005];
int b[300005];
void cardp(int k){
	stack<int> t;
	int f[300005]={0};
	for(int i=k;i<=n;i++){
		if(f[a[i]]==1){
			while(t.top()!=a[i]){
				f[t.top()]=0;
				t.pop();
			}
		}else{
			t.push(a[i]);
			f[a[i]]=1;
		}
	}
	while(!t.empty()){
		b[t.top()]++;
		t.pop();
	}
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cardp(i);
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
