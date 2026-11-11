//GZ-J00319 卓然 贵阳中天中学 
#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool v[300005];
long long ans[300005];
int n,m;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int s=1;s<=n;s++){
		memset(v,0,sizeof(v));
		stack<int> q;
		for(int i=s;i<=n;i++){
			if(v[a[i]]){
				while(q.top()!=a[i]){
					v[q.top()]=false;
					q.pop();
				}
				continue;
			}
			v[a[i]]=true;
			q.push(a[i]);
		}
		for(int i=1;i<=m;i++){
			if(v[i])ans[i]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
