#include<bits/stdc++.h>
using namespace std;
int n,m,l;
int a[500050],cnt[300050],ans[300050];
queue<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(cnt[a[j]]==0){
				q.push(a[j]);
				cnt[a[j]]++;
				l++;
			}else{
				int k=l;
				bool f=1;
				while(k--){
					if(q.front()==a[j]&&f){
						q.push(q.front());
						f=0;
					}else if(f){
						q.push(q.front());
					}else{
						cnt[q.front()]--;
						l--;
					}
					q.pop();
				}
			}
		}
		while(!q.empty()){
			if(cnt[q.front()]!=0) ans[q.front()]++;
			cnt[q.front()]=0;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
