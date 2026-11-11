#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a[100005],f,b[1005][100005],l[1005][100005],maxf=INT_MAX,s,e,w[10003];
bool x[100005][1005];
long long index(long long station,long long line){
	for(int j=1;j<=f;j++){
		if(b[line][j]==station){
			return j;
		}
	}
	return -1;
}
void dfs(long long line,long long start,long long now,long long end,long long footmeter,bool first,long long firstline){
	if(now==end) {
		if(maxf>=footmeter)
		{
			int u = index(s,firstline);
			maxf=footmeter+a[end]+l[firstline][u]+l[line][index(end,line)];
			return;
		} 
	}
	
	//¼ÌÐø³Ë×ø£º
	int j=index(now,line);
	x[now][line]=1;
	if(j+1<=w[line]&&x[b[line][j+1]][line]==0) dfs(line,start,b[line][j+1],end,footmeter,0,firstline);
	
	else if(j-1>=0&&x[b[line][j-1]][line]==0)dfs(line,start,b[line][j-1],end,footmeter,0,firstline);
	//ÏÂ³µ: 
	
	for(int i=1;i<=n;i++){
		if(i!=line) {
			int u1 = index(now,i);
			int u2 = index(now,line);
			if(u1 != -1&&x[now][i]!=1){
				if(first) dfs(i,start,b[i][u1],end,footmeter,0,i);
				else dfs(i,start,b[i][u1],end,footmeter+l[i][u1]+l[line][u2],0,firstline);
			}
		}
	}
	
	x[now][line]=0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>f;
		w[i]=f;
		for(int j=1;j<=f;j++){
			cin>>b[i][j];
			cin>>l[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>s>>e;
		for(int i=1;i<=n;i++){
			int u = index(s,i);
			if(u != -1){
				dfs(u,s,s,e,a[s],1,i);
			} 
			
		}
		cout<<maxf<<endl;
		maxf=INT_MAX;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=f;j++){
				x[i][j]=0;
			}
		}
	}
		
	
	return 0;
} 
