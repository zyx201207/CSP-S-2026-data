#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500500],ans[300300],cunzai[300300];
queue<long long>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		memset(cunzai,0,sizeof(cunzai));
		for (int j=i;j<=n;j++){
			if (cunzai[a[j]]==0){
				q.push(a[j]);
				cunzai[a[j]]=1;
			}else{
				while (q.front()!=a[j]){
					cunzai[q.front()]=0;
					q.pop();
				}
			}
		}
		for (int j=1;j<=m;j++){
			if (cunzai[j]==1){
				ans[j]+=1;
			}
		}
	}
	for (int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
