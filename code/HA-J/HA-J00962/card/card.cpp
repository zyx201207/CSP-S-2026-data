#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+10;
int a[maxn],flag[maxn];
bool st[maxn];
stack<int> stk;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k=1;
	int t=n;
	while(t--){
		for(int i=k;i<=n;i++){
			if(!st[a[i]]){
				stk.push(a[i]);
				st[a[i]]=true;
			}
			else{
				while(stk.top()!=a[i]){
					st[stk.top()]=false;
					stk.pop();
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(st[i]){
				flag[i]++;
				st[i]=false;
			}
		}
		k++;
	}
	for(int i=1;i<=m;i++){
		if(flag[i]!=0) cout<<flag[i]<<" ";
	}
	return 0;
}
