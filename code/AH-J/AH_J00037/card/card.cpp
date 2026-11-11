#include<bits/stdc++.h>
using namespace std;
int cnt[300005];
stack<int> s;
stack<int> st;
int a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int f=0;
			while(!s.empty()){
				st.push(s.top());
				s.pop();
				if(s.top()==a[i]){
					f=1;
					break;
				}
			}
			if(f==0){
				while(!st.empty()){
					s.push(st.top());
					st.pop();
				}
			}
			s.push(a[i]);
			while(!st.empty()) st.pop();
		}
		while(!s.empty()){
			cnt[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
