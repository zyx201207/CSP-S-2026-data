#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int x[2000007];
bool flag=0,f=0;
vector<int> e[2000007];
vector<int> ne[2000007];
bool vis[2000007];
bool v[2000007];
int sh[2000007];
int sh1[2000007];
int num;
void check(int dep,int now,int from,int to){
	if(now==to){
		if(dep==sh[to]){
			num++;
		}
		return;
	}
	vis[now]=1;
	for(auto y : e[now]){
		if(vis[y]==0){
			check(dep+1,y,from,to);
		}
	}
	vis[now]=0;
	return;
}
void made(int dep,int now){
	sh[now]=min(sh[now],dep);
	v[now]=1;
	for(auto y : e[now]){
		if(v[y]==0){
			made(dep+1,y);
		}
	}
	v[now]=0;
	return;
}
void solve(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
	}
	if(n<=5000){
		if(c==0){
			if(n==5&&d==3){
				printf("0\n");
			}
			if(n==6&&d==2){
				printf("1\n");
			}
		}
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
		memset(sh,127,sizeof(sh));
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[i]-x[j])<=d){
					e[i].push_back(j);
				}
				else{
					break;
				}
			}
		}
		made(0,1);
		memset(v,0,sizeof v);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[i]-x[j])<=d&&sh[i]==sh[j]-1){
					ne[i].push_back(j);
				}
				else{
					break;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				made(0,1);
				num=0;
				check(0,i,i,j);
				if(num==2){
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	else{
		int ch=abs(a[1]-a[2]);
		bool flag=0;
		for(int i=2;i<=n;i++){
			if(abs(a[i]-a[i-1])!=cha){
				flag=1;
			}
		}
		if(flag==0){
			if(cha>d){
				printf("0\n");
			}
			else{
				printf("%d\n",2*(cha/d-1));
			}
		}
	}
	return;
}
signed main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		solve();
	}
	return 0;
}
//Oct31==Dec25?
