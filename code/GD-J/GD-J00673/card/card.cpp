#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn=5e5+5,mod=1e9+7;
int vis[maxn],ans[maxn],a[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (n>=5e3){
		if (m==1) cout<<n;
		else{
			for (int i=1;i<=n;i++) ans[a[i]]=i;
			for (int i=1;i<=m;i++) cout<<ans[i]<<" ";
		}
		return 0;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) vis[j]=0;
		stack<int> st;
		for (int j=i;j<=n;j++){
			if (vis[a[j]]) {
				while (!st.empty()){
					int r=st.top();
					st.pop();
					vis[r]=0;
					if (r==a[j]) break;
				}
			}
			st.push(a[j]);
			vis[a[j]]=1;
		}
		while (!st.empty()){
			int r=st.top();
			st.pop();
			ans[r]++;	
		}
	}
	for (int i=1;i<=m;i++) cout<<ans[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}


