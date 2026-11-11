#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,a[2000005],n,d,pd,zd,ans;
struct node{
	int now;
	int flag;
	int step;
}x,y;
queue<node>q;
void bfs(){
	while(!q.empty()){
		x=q.front();
		q.pop();
		if(x.now==x.flag&&zd==0){
			pd++;zd=x.step;
		}
		else if(x.now==x.flag&&zd==x.step){
			pd++;
		}
		int mb=x.now,xs=x.step+1;
		while(mb<=n&&pd==0){
			mb++;
			if(a[mb]-a[x.now]<=d){
				y.now=mb;
				y.flag=x.flag;
				y.step=xs;
				q.push(y);	
			}
			else break;
		}
	}
	if(pd==2)ans++;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				pd=0,zd=0;
				y.now=i;
				y.flag=j;
				y.step=0;
				q.push(y);
				bfs();
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

