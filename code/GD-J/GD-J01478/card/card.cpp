#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N],b[M];
stack<int> st;
bool v[M];	

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			if(!v[a[j]]){
				v[a[j]]=1;
				st.push(a[j]);
			}else{
				while(st.top()!=a[j]){
					v[st.top()]=0;
					st.pop();
				}
				v[st.top()]=0;
				st.pop();
				v[a[j]]=1;
				st.push(a[j]);
			}
		}
		while(!st.empty()){
			//cout<<st.top()<<' ';
			v[st.top()]=0;
			b[st.top()]++;
			st.pop();
		}
		//cout<<'\n';
	}
	for(int i=1;i<=m;++i){
		cout<<b[i]<<' ';
	}
	return 0;
}
