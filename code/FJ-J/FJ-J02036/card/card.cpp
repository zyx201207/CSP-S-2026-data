#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	stack<int> st;
	bool v[300005];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(v[a[j]]==1){
				while(1){
					if(st.top()==a[j]) break;
					v[st.top()]=0;
					st.pop();
				}
			}else{
				st.push(a[j]),v[a[j]]=1;
			}
		}
		while(1){
			if(st.size()==0) break;
			cnt[st.top()]++,v[st.top()]=0,st.pop();
		}
	} 
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}

