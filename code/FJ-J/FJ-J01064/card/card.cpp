#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
stack<int> st;
bool flag[N];
int ans[N];
int a[N];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(flag,0,sizeof(flag));
		for(int j=i;j<=n;j++){
			if(flag[a[j]]==0){
				flag[a[j]]=1;
				st.push(a[j]);
			}else{
				while(st.top()!=a[j]){
					flag[st.top()]=0; 
					st.pop();
				}
			}
		}
		while(!st.empty()){
			int k=st.top();
			st.pop();
			ans[k]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
