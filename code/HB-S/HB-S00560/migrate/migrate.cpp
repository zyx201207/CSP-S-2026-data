#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,j,k,m,ans=-100,c,t,dot=0;
int a[1000005];
bool fl[100005];
priority_queue<int>q[1005][1005];

int minst=LLONG_MAX,mstpos=LLONG_MAX;
void dfs(int dt,int st){
	
	if(dt!=dot) q[dot][dt].push(st);
	if(dt!=dot) q[dt][dot].push(st);
	fl[dt]=1;
	
	for(int i=dt-1;i>=1;i--){
		if(abs(a[dt]-a[i])>m) break;
		if(fl[i]==0){
			fl[i]=1;
			dfs(i,st+1);
			fl[i]=0;
		}
	}
	for(int i=dt+1;i<=n;i++){
		if(abs(a[dt]-a[i])>m) break;
		if(fl[i]==0){
			fl[i]=1;
			dfs(i,st+1);
			fl[i]=0;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	
	while(t--){
		memset(a,0,sizeof(a));
		memset(q,0,sizeof(q));
		memset(fl,0,sizeof(fl));
		int cnt=0;
		cin>>n>>m;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		for(i=1;i<=n;i++){
			dot=i;
			dfs(i,1);
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				//cout<<q[i][j].size()<<" ";
				if(q[i][j].size()==2){
					
				//	priority_queue<int>q;
				//	cout<<q.front();
					int f=q[i][j].top();
					
					//cout<<f<<" ";
					q[i][j].pop();
					//cout<<q[i][j].top();
					if(q[i][j].top()==f) cnt++;
				}
				else if(q[i][j].size()>2){
					int f1=q[i][j].top();
					//cout<<f1<<" ";
					q[i][j].pop();
					if(q[i][j].top()==f1){
						int f2=q[i][j].top();
						//cout<<f2<<" ";
						q[i][j].pop();
						//cout<<q[i][j].top();
						if(q[i][j].top()!=f2) cnt++;
					}
				}
				//cout<<endl;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
/* 
5 5
1 2 4 8 9
*/
