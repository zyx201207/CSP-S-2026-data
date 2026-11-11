#include <bits/stdc++.h>
using namespace std;
int n,m,a[2010],ans;
bool hav[2010];
int yes[2010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int game=1;game<=n;game++){
		for(int i=1;i<=m;i++)hav[a[i]]=0;
		stack<int> stk;
		for(int i=game;i<=n;i++){
			if(hav[a[i]]){
				while(stk.top()!=a[i])stk.pop();
			}
			else{
				stk.push(a[i]);
				hav[a[i]]=1;
			}
		}
		while(!stk.empty()){
			yes[stk.top()]++;
			stk.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<yes[i]<<' ';
	return 0;
}
