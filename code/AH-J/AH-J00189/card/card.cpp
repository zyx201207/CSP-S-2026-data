#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],b[M],c[N],mp[N];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		memset(c,0,sizeof c);
		memset(mp,0,sizeof mp);
		for(int j=i;j<n;j++){
			if(mp[a[j]]==0){
				mp[a[j]]++;
				st.push(a[j]);
			}
			else{
				while(st.top()!=a[j]){
					mp[st.top()]=0;
					st.pop();
				}
			}
		}
		while(!st.empty()){
			if(c[st.top()]==0){
				c[st.top()]++;
				b[st.top()]++;
			}
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
