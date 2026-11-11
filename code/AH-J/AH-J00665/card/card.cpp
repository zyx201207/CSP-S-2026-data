#include<bits/stdc++.h>
using namespace std;
int m,n,a[500010],ans[300010];
bool t[300010];
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long T=1;T<=n;T++){
		stack<int> st;
		memset(t,false,sizeof(t));
		for(long long i=T;i<=n;i++){
			if(t[a[i]]==0){
				st.push(a[i]);
				t[a[i]]=1;
			}
			else{
				while(st.top()!=a[i]) {t[st.top()]=0;st.pop();}
			}
		}
		for(long long i=1;i<=m;i++){
			ans[i]+=t[i];
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
