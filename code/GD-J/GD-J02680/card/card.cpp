#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],now[300005];
stack<int> q;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int k=a[j];
			if(now[k]==0){
				q.push(k);now[k]++;
			}
			else{
				while(q.top()!=k){
					now[q.top()]--;
					q.pop();
				}
			}
		}
		while(!q.empty()){
			b[q.top()]++,now[q.top()]--;
			q.pop();
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
