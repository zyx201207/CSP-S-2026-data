#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],ans[200001],cnt[200001];
stack<int>st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=1;j<=n;j++){
		memset(cnt,0,sizeof(cnt));
		for(int i=j;i<=n;i++){
			if(cnt[a[i]]>0){
				while(cnt[a[i]]>0){
					cnt[st.top()]--;					
					st.pop();
				}
			}
			st.push(a[i]);
			cnt[a[i]]++;
		}
		while(st.size()){
			ans[st.top()]++;
			st.pop();
		}			
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
} 
