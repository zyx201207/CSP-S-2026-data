#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int c,n,m,d,q,w[1010],k[510],a[501][1010],t[501][1010],st,en,v[1010][510],sum=1e9;
void dfs(int x,int step,int line,int linel){
	//cout<<x<<" "<<step<<" "<<line<<" "<<linel<<endl;
	//_sleep(100); 
	if (x==en){;
		sum=min(sum,step+w[en]+t[line][linel]);
		return;
	}
	v[x][line]=1;
	/*
	0 3 7 20 2
	8  3 6 1 7 2 9
	
	3  1 4  2 5  5 100
	3  2 6  3 1  7 2
	4  3 2  5 100 4 6 6 7
	2 3
	*/
	if (linel>1&&line!=0&&v[a[line][linel-1]][line]==0) dfs(a[line][linel-1],step,line,linel-1);
	if (linel<k[line]&&line!=0&&v[a[line][linel+1]][line]==0) dfs(a[line][linel+1],step,line,linel+1);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=k[i];j++){
			if (a[i][j]==x&&v[x][i]==0){
				dfs(a[i][j],step+t[i][j]+t[line][linel],i,j);
			}
		}
	}
	v[x][line]=0;
	//cout<<endl;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++){
		cin>>k[i];
		for (int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while (q--){
		cin>>st>>en;
		sum=1e9;
		
		dfs(st,w[st],0,0);
		cout<<sum<<endl;
	}
	return 0;
} 
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
