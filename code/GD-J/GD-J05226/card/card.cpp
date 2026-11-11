#include<iostream>
#include<stack>
using namespace std;
const int N=5*1e5+10, M=3*1e5+10;
int n,m,a[N],ans[M],vis[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		stack<int> st;
		for(int i=k;i<=n;i++){
			if(vis[a[i]]){
				while(!st.empty()&&st.top()!=a[i]){
					int l=st.top();
					st.pop();
					vis[l]=0;
				}
			}
			else{
				st.push(a[i]);
				vis[a[i]]=1;
			}
		}
		for(int i=1;i<=m;i++){
			if(vis[i]) ++ans[i];
			vis[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i!=m) cout<<' ';
		else cout<<'\n';
	}
	return 0;
}
