#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		queue<int> q;
		queue<int> q2;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=sizeof(q);k++){
				if(q.size()){
					int x=q.front();
					q.pop();
					if(x==a[j]){
						while(q.size()) q.pop();
					}
					else q2.push(x);
				}
			}
			q2.push(a[j]);
			for(int k=1;k<=sizeof(q2);k++){
				if(q2.size()){
					q.push(q2.front());
					q2.pop();
				}
			} 
		}
		while(q.size()){
			int x=q.front();
			q.pop();
			ans[x]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
