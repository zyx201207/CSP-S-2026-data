#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
short c;
int t,d,n,a[2000005],ans;
bool vis[2000005];
struct stu{
	int dd;
	int lj;
};
void bfs(int s,int e){
	queue<stu>q;
	q.push(stu{s,0});
	vis[s]=1;
	int mx=2100000000,cnt=0;
	while(!q.empty()){
		stu f=q.front();
		q.pop();
		for(int i=f.dd;i<=n;i++){
			if(!vis[i]&&(max(a[i],a[f.dd])-min(a[f.dd],a[i]))<=d){
				if(i==e){
					if(f.lj+1<mx){
						cnt=1;
						mx=f.lj+1;
						vis[n]=0;
					}else if(f.lj+1==mx){
						cnt++;
						vis[n]=0;
					}
				}else{
					q.push(stu{i,f.lj+1});
					vis[i]=1;
				}
			}
		}
	}
	if(cnt==2){
		ans++;
	}
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				bfs(j,k);
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}

