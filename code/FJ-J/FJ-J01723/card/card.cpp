#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],flag[N],cnt[N];
stack<int> s[N];
deque<int> q[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++) flag[i]=1;
	for(int i=n;i>=1;i--){
		int j=i;
		while(j<=n){
			while(s[a[j]].size()){
				if(s[a[j]].top()<=j){
					q[a[j]].push_front(s[a[j]].top());
					s[a[j]].pop();
				}else{
					break;
				}
			}
			if(s[a[j]].size()){
				for(int k=j+1;k<=s[a[j]].top();k++){
					flag[k]=0;
				}
				j=s[a[j]].top()-1;
				q[a[j]].push_front(s[a[j]].top());
				s[a[j]].pop();
			}
			j++;
		}
		for(int o=i;o<=n;o++){
			if(flag[o]){
				cnt[a[o]]++;
			}
			flag[o]=1;
		}
		for(int u=1;u<=m;u++){
			while(q[u].size()){
				s[u].push(q[u].back());
				q[u].pop_back();
			}
		}
		s[a[i]].push(i);
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
} 
