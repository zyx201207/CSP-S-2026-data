#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],lst[N],pre[N];
long long ans[N];
bool vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==2){
		ans[a[n]]=n;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[n])
				ans[a[i]]++;
		}
	}
	else if(n>=5000){
		vector<stack<int>>d(n+1);
		for(int i=n;i>=1;i--){
			pre[i]=lst[a[i]];
			lst[a[i]]=i;
		}
		stack<int>st;
		for(int i=n;i>=1;i--){
			if(pre[i])
				st=d[pre[i]];
			else
				st.push(a[i]);
			d[i]=st;
		}
		for(int i=1;i<=n;i++){
			while(!d[i].empty()){
				ans[d[i].top()]++;
				d[i].pop();
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			stack<int>st;
			for(int j=i;j<=n;j++){
				int x=a[j];
				if(!vis[x]){
					st.push(x);
					vis[x]=true;
				}
				else{
					while(st.top()!=x){
						vis[st.top()]=false;
						st.pop();
					}
				}
			}
			while(!st.empty()){
				vis[st.top()]=false;
				ans[st.top()]++;
				st.pop();
			} 
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' '; 
	return 0;
} 
