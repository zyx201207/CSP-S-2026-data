#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>a,res;
stack<int>stk;
vector<bool>inStk;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	a.resize(n+1,0);
	res.resize(n+1,0);
	inStk.resize(n+1,0);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!inStk[a[j]]){
				inStk[a[j]]=1;
				stk.push(a[j]);
			}
			else{
				while(!stk.empty()&&stk.top()!=a[j]){
					inStk[stk.top()]=0;
					stk.pop();
				}
			}
		}
		while(!stk.empty()){
			res[stk.top()]++;
			inStk[stk.top()]=0;
			stk.pop();
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",res[i]);
	}
	return 0;
}
