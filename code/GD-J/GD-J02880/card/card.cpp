#include<bits/stdc++.h>
using namespace std; 
const int N=5e5+5,M=3e5+5;
int pre[N],n,m,a[N],suf[N],lst[N],ans[M],lst2[M];
vector<int> pos;
priority_queue<int> q;
int main(){
	cin>>n>>m;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=1;i<=n;i++) lst2[i]=1e9;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=lst[a[i]];
		lst[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
		while(!q.empty()&&q.top()>=i)q.pop();
		if(!q.empty()){
			ans[a[i]]+=max(min(i,lst2[a[i]])-q.top(),0);
			lst2[a[i]]=min(lst2[a[i]],q.top());
		}
		else{
			ans[a[i]]+=max(min(i,lst2[a[i]]),0);
			lst2[a[i]]=0;
		}
		q.push(pre[i]);
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
