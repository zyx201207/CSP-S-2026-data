#include<bits/stdc++.h>
using namespace std;
int n,m,ans[500010],a[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=n;
	while(sum--){
		stack<int> q;
		bool st[500010]={false};
		for(int i=n-sum;i<=n;i++){
			if(!st[a[i]]){
				q.push(a[i]);
				st[a[i]]=true;
			}else {
				while(1){
					if(q.top()==a[i]){
						q.pop();
						q.push(a[i]);
						break;
					}else {
						st[q.top()]=false;
						q.pop();
					}
				}
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
	fclose(stdin);
	fclose(stdout);
	return 0;
}
