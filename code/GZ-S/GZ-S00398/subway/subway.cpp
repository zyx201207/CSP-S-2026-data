//GZ-S00398 ·¶Ώ£γρ 
#include <bits/stdc++.h>
using namespace std;

int sub[501][501];//the subway can go where 
int numb[501];//the subway 's number to other 
int stasub [501][501];//every station to every subway 's value
int c,n,m,d,q;//n is number of subway and m is number of station 
int ans=0;
int cnt=1000000;
bool ok[501];


void dfs(int x,int y,int sub_now){
	//s.push(x);
	int now=x;
	cout<<now<< ' ';
	ok[now]=1;
	//s.pop();
	if(now==y){
		cnt=min(cnt,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(stasub[now][i]!=0){
			//ans+=(stasub[now][i]);
			if(sub_now!=i){
				ans+=(stasub[now][i]);
				if(sub_now!=0){
					ans+=(stasub[now][sub_now]);
				}
			}
			
			for(int j=1 ; j<=numb[i] ;j++){
				int t=sub[i][j];
				if(ok[t]==0)
					dfs(t,y,i);
				ok[t]=1;
			}
			
			if(sub_now!=i){
				ans-=(stasub[now][i]);
				if(sub_now!=0){
					ans-=(stasub[now][sub_now]);
				}
			}
			
		}
	}
	return;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	int station[501];
	for(int i=1;i<=m;i++){
		cin>>station[m];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			stasub[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			stasub[x][i]=y;
			sub[i][j]=x;
		}
		numb[i]=k;
	}
	
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=numb[i];j++){
//			cout<<sub[i][j]<<' ';
//		}
//		cout<<'\n';
//	} 
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ans=station[x]+station[y];
		dfs(x,y,0);
		cout<<ans<<'\n';
		ans=0;
		for(int j=1;j<=m;i++){
			ok[m]=0;
		}
	}
	return 0;
}
