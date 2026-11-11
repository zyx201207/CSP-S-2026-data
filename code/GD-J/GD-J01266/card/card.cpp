#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> stk;
		int f[N];
		for(int j=0;j<=N;j++){
			f[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(f[a[j]]>0){
				while(stk.top()!=a[j]){
					stk.pop();
				}
				f[a[j]]=1;
			}else{
				f[a[j]]++;
				stk.push(a[j]);
			}
		}
		while(!stk.empty()){
			ans[stk.top()]++;
			stk.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}
