#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e5+5;
const int M=3e5+5;
int a[N],n,m;
int last[M];
bool vis[M];
int sum[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	bool subtask1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) subtask1=0;
	}
	if(subtask1){
		for(int i=1;i<=n;i++){
			last[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<last[i]<<' ';
		}
		cout<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		stack < int > st;
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			while(vis[a[j]]){
				int text=st.top();st.pop();
				vis[text]=0;
			}
			vis[a[j]]=1;
			st.push(a[j]);
		}
		for(int j=1;j<=m;j++){
			sum[j]+=vis[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
	cout<<endl;
	return 0;
}
