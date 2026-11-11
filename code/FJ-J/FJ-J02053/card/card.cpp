#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
deque<int>t;
int n,m;
int a[500005],cnt[300005],vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);  
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i+1;j<=n;j++){
			if(vis[a[j]]){
				while(!t.empty()&&t.back()!=a[j]){
					vis[t.back()]=0;
					t.pop_back();
				}
			}else{
				t.push_back(a[j]);
				vis[a[j]]=1;
			}
		}
		while(!t.empty()){
			cnt[t.front()]++;
			t.pop_front();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
