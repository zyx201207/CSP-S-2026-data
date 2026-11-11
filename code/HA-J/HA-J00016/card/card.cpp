#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+7;
const int M=3e5+7;
int a[N];
int ans[M];
bool ins[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	set<int> st;
//	for(int i=1;i<=n;i++){
//		st.insert(a[i]);
//	} 
//	for(int i=1;i<=m;i++){
//		ans[i]=i;
//	}
//	for(int i=1;i<=m;i++){
//		cout<<ans[i]<<' ';
//	} 
	stack<int> stk;
	for(int i=1;i<=n;i++){
		memset(ins,false,sizeof(ins));
		stk.push(a[i]);
		ins[a[i]]=true;
		for(int j=i+1;j<=n;j++){
			if(ins[a[j]]){
				while(!stk.empty()&&stk.top()!=a[j]){
					stk.pop();
				}
			}else{
				stk.push(a[j]);
			}
		}
		while(!stk.empty()){
			int x=stk.top();
//			cout<<x<<'\n';
			stk.pop();
			ans[x]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
