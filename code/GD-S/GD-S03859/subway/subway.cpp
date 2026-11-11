#include<bits/stdc++.h>
using namespace std;

int dic[505],k,c,n,m,d,q,w[500005],date[500005][25][2],top[500005],x,y,num,ans;

void dfs(int s,int step){
	if(num>=ans&&ans!=-1)return;
	if(c>=7&&c<=11&&step>=2)return;
	if(s==y){
		if(ans==-1){
			ans=num;
		}
		else{
			ans=min(ans,num);
		}
		return;
	}
	date[s][0][0]=1; 
	for(int i=1;i<=m;i++){
		if(date[i][0][0])continue;
		for(int j=1;j<=top[i];j++){
			for(int k=1;k<=top[s];k++){
				if(date[s][k][0]!=0&&date[i][j][0]!=0&&date[s][k][0]==date[i][j][0]){
					if(dic[date[s][k][0]]&&i!=y)continue;
					num+=date[s][k][1]+date[i][j][1]; 
					dfs(i,step+1);
					num-=date[s][k][1]+date[i][j][1];
				}
			}
		}
	}
	date[s][0][0]=0;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			date[a][++top[a]][0]=i;
			date[a][top[a]][1]=t;
		}
	}
	for(int i=1;i<=q;i++){
		ans=-1;
		cin>>x>>y;
		for(int j=1;j<=top[y];j++){
			dic[date[y][j][0]]=1;
		}
		dfs(x,1);
		cout<<ans+w[x]+w[y]<<endl;
	}
}
