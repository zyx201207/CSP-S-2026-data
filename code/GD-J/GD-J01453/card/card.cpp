#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
bool flag[M];
int a[N],t[M];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(flag,0,sizeof(flag));
		for(int j=i;j<=n;j++){
			if(flag[a[j]]){
				while(st.top()!=a[j]) flag[st.top()]=0,st.pop();
				st.pop();
			}
			st.push(a[j]);
			flag[a[j]]=1;
		}
		while(!st.empty()) t[st.top()]++,st.pop();
	}
	for(int i=1;i<=m;i++) cout<<t[i]<<' ';
	return 0;
}
