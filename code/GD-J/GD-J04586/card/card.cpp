#include <bits/stdc++.h>
using namespace std;
const int N=500010,M=300010;
int n,m;
int a[N],last[M],ans[M];
int num_in_q[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		stack<int> q;
		memset(last,-1,sizeof last);
		for(int j=i;j<=n;j++){
			if(last[a[j]]!=-1){
				while(!q.empty() and q.top()!=a[j]){
					last[q.top()]=-1;
					q.pop();
				}
			}
			else{
				q.push(a[j]);
				last[a[j]]=1;
			}
		}
		while(!q.empty()){
			ans[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
