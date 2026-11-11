#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10,M=3*1E5+10;
stack<int> st;
int a[N],ans[M];
bool v[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!v[a[j]]){
				v[a[j]]=1;
				st.push(a[j]);
			}else{
				while(st.top()!=a[j]){
					v[st.top()]=0;
					st.pop();
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(v[i]) ans[i]++;
			v[i]=0;
		}
		while(!st.empty()) st.pop();
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}

