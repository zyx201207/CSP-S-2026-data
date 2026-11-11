#include<bits/stdc++.h>
using namespace std;
int a_m[100005],a[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=200005){
		for(int i=1;i<=n;i++){
			stack<int> st;
			bool cnt[100005]={false};
			for(int j=i;j<=n;j++){
				if(cnt[a[j]]){
					while(st.top()!=a[j]){
						cnt[st.top()]=false;
						st.pop();
					}
				}
				else{
					st.push(a[j]);
					cnt[a[j]]=true;
				}
			}
			while(!st.empty()){
				a_m[st.top()]++;
				st.pop();
			}
		}
		for(int i=1;i<=m;i++){
			cout<<a_m[i]<<" ";
		}
	}
	return 0;
}
