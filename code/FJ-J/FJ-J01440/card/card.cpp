#include <bits/stdc++.h>
using namespace std;
int a[500005];
int book[300005];
int cnt[300005];
int q[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			book[j]=0;
		}
		deque<int> q;
		for(int j=i;j<=n;j++){
			if(book[a[j]]==1){
				while(!q.empty()){
					if(q.back()!=a[j]){
						book[q.back()]=0;
						q.pop_back();
					}
					if(!q.empty()&&q.back()==a[j]){
						q.pop_back();
						break;
					}
				}
				q.push_back(a[j]);
				int b=q.front();
			}else{
				book[a[j]]=1;
				q.push_back(a[j]);
			}
		}
		while(!q.empty()){
			cnt[q.back()]++;
			q.pop_back();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	
	return 0;
}
