#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005],ans=0;
struct node{
	int now,past;
}head,tail;
void bfs(int x,int y){
	int sum=0,minn=-1;
	vector<int>mapp(n+1,0);
	queue<node>q;
	tail={x,0};
	q.push(tail);
	mapp[x]=1;
	while(!q.empty()){
		head=q.front();
		q.pop();
		if(head.now==y&&minn==-1){
			minn=head.past;
			sum++;
			continue;
		}
		else if(head.now==y&&minn!=-1){
			if(head.past==minn){
			    sum++;
			    continue;
			}
			if(head.past!=minn)return;
		}
		for(int p=head.now+1;p<=y;p++){
			if(a[p]-a[head.now]<=d&&!mapp[p]){
				tail={p,head.past+1};
				q.push(tail);
				if(p!=y)mapp[p]=1;
			}
		}
	}
	if(sum==2){
		ans++;
		return;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(int pl=1;pl<=t;pl++){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				bfs(i,j);
			}
		}
		cout<<ans<<"\n";
	}
}
