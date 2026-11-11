#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005];
bool u[500005];
vector<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(u,0,sizeof(u));
		for(int j=i;j<=n;j++){
			if(u[a[j]]==1){
				while(q.back()!=a[j]){
					u[q.back()]=0;
					q.pop_back();
				}	
			}else{
				q.push_back(a[j]);
				u[a[j]]=1;
			}	
			if(j==n){
				while(!q.empty()){
					b[q.back()]++;
					q.pop_back();
				}
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	
}
