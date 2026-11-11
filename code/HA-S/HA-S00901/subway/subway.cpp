#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10,l=1e4;
int c,n,d;
ll num,T,m,q,w[N],x,y,p,a,t[l][l],zhan[l][l];
cha(ll ui,ll r){
		ui++;
	if(zhan[ui][r]==0){
		return cha(ui,r);
	}
	else 
		return ui;
}
int main(){
	freopen("subway.in.txt","r",stdin);
	freopen("subway.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>p;
	 	for(int j=1;j<=p;j++){
			cin>>a>>T;
			zhan[i][a]++;
			t[i][a]=T;
		}
	}
	
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		num=w[x]+w[y];
		for(int j=x;j<=y;j++){
			
			num+=t[x][j];
			
			if(j+1<=y)
				if(zhan[x][j+1]==0)
				{
					num+=t[cha(x,j)][j];
					x=cha(x,j);
				
				}
				
			if(zhan[x][y]>0 && y-x>1 ){
				num+=t[x][y];
				break;
			}
				
		}
		cout<<num<<"\n";
	}
		
			
	return 0;
} 

