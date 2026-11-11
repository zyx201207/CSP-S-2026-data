#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],ans[300005];
bool b[300005];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof b);
		for(int j=i;j<=n;j++){
			if(!b[a[j]]){
				b[a[j]]=1,st.push(a[j]);
			}else{
				while(1){
					int x=st.top();
					st.pop();
					b[x]=0;
					if(x==a[j])
						break;
				}
				st.push(a[j]);
				b[a[j]]=1;
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
} 
