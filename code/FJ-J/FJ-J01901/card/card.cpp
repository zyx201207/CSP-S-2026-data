#include<bits/stdc++.h>
using namespace std;
#define int long long
int m,n,a[500001],c[300001];
bool b[300001];
stack<int> st;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=m;i++){
			b[i]=0;
		}
		for(int i=j;i<=n;i++){
			if(!b[a[i]]){
				b[a[i]]=1;
				st.push(a[i]);
			}
			else{
				while(st.top()!=a[i]){
					b[st.top()]=0;
					st.pop();
				}
			}
		}
		while(!st.empty()){
			c[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
