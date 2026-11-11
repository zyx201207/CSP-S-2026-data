#include<bits/stdc++.h>
using namespace std;
const int N=3*1e5+55;
int n,m,a[500005];
int p[N],te[N];
queue<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(te[a[j]]==1){
				int s=q.size();
				bool f=false;
				while(s--){
					if(q.front()==a[j]) f=true;
					if(f) te[q.front()]=0,q.pop();
					else q.push(q.front()),q.pop();
				}
			}
			q.push(a[j]),te[a[j]]++;
		}
		while(!q.empty()){
			int t=q.front();
			p[t]++;q.pop();
			te[t]=0;
		}
	}
	for(int i=1;i<=m;i++) cout<<p[i]<<" ";
	return 0;
}
