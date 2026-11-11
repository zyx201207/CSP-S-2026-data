#include<bits/stdc++.h>
using namespace std;
struct railway{
	int huanzhanshijian;
}r[400][400];
bool t[500005][21];
struct station{
	int zhantaishijian;
}s[500005];
int c,n,m,d,q,ds,k,x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	if(c>=9)return 0;
	for(int i=1;i<=m;i++){
		cin>>s[i].zhantaishijian ;
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>ds;
			cin>>r[ds][k].huanzhanshijian ;
			t[ds][k]=1;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		for(int j=1;j<=n;j++){
			if(t[x][j]==1 && t[y][j]==1){
				cout<<s[x].zhantaishijian +s[y].zhantaishijian +r[x][j].huanzhanshijian +r[y][j].huanzhanshijian<<endl;
			break;
			}
		}
	}
	return 0;
}
