#include<bits/stdc++.h>
using namespace std;
int n,m;
int const N = 5e5 + 5,M = 3e5 +5;
int a[N],b[M]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		stack<int> st;
		bool p[M] = {}; 
		for(int j=i;j<=n;j++){
			int d=a[j];
			if(p[d]){
				while(st.size()){
					int w=st.top();st.pop();
					p[w] = 0;
					if(w==d) break; 
				} 
			}
			st.push(d);
			p[d] = 1; 
		}
		for(int i=1;i<=m;i++){
			if(p[i]) b[i] ++; 
		} 
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" "; 
	return 0;
}
