#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[500010];
queue <int> q,p;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdin);
	//ysjfNB
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		while(q.empty()) q.pop();
		while(p.empty()) p.pop();
		for(int j=i;j<=n;j++){
			p=q;
			while(!q.empty()&&q.front()==a[j]){
				q.pop();
			}
			if(q.empty()) q=p;
			q.push(a[j]);
		}
		while(!q.empty()){
			ans[q.front()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
