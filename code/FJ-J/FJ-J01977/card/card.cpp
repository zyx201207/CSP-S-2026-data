#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int op,n,m;
int a[N];
stack<int> st;
int ans[N],in[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(in[a[j]]){
				while(!st.empty()&&st.top()!=a[j]){
					in[st.top()]--;
					st.pop();
				}
			}else{
				st.push(a[j]);
				in[a[j]]++;
			}
			
		}
		while(!st.empty()){
			ans[st.top()]++;
			in[st.top()]--;
			st.pop();
		}
	}
    for(int i=1;i<=m;i++){
    	cout<<ans[i]<<" ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1

4 3
1 2 1 3

*/
