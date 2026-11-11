#include <bits/stdc++.h>
using namespace std;
int a[500005],cnt[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> st;
		for(int j=i;j<=n;j++){
			if(st.top()==a[j]){
				int q=st.top();
				st.pop();
				while(st.top()!=q){
					cnt[st.top()]=0;
					st.pop();
				}
			}
			else{
				st.push(a[j]);
				cnt[a[j]]=1;
			}
		}
		for(int j=1;j<=5000;j++){
			if(cnt[i]){
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
