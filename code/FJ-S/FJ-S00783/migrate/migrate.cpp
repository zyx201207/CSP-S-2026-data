#include<bits/stdc++.h>
using namespace std;
queue<long long>q[2];
long long c=0,t,n,z,x[10000005],a[10000005],f[10000005]={0};
struct innn{
	long long b=0,k=1;	
}d[1000005];
void bfs(int s){
	q[0].push(x[s]);
	q[1].push(s);
	while(!q[0].empty()){
		int o=q[0].front(),u=q[1].front();
		q[0].pop();
		q[1].pop();
		int i=u+1;
		while(o+z>=x[i]&&i<=n){
			if(d[i].b>d[u].b+1||d[i].b==0){
			d[i].b=d[u].b+1;
			d[i].k=1;	
			}
			else if(d[i].b==d[u].b+1)d[u].k++;
			if(f[i]==0){
				f[i]=1;
			q[0].push(x[i]);
			q[1].push(i);
			}
			i++;
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t){
		t--;
		cin>>n>>z;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		d[1].b=0;
		for(int i=1;i<=n;i++){
			if(f[i]==0)bfs(i);
		for(int i=1;i<=n;i++){
			if(d[i].k==2)c++;
		}
		}
		
		cout<<c;
	}
	return 0;
} 
