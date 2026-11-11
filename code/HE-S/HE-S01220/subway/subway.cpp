#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,q;
int w[500005];
struct stop{
	int stage,t;
};
vector <stop> a[505];
vector <int> roal[500005];
bool empty[500005];
int start,end;
ll ans=1e18;
void dg(int x,bool bj[500005],int t,char condition){
	if(x==end){
		ans=min(int(ans),t);
		return ;
	}
	if(condition=='c')
		for(int i=0;i<a[x].size();i++){
			if(!bj[a[x][i].stage]){
				bj[a[x][i].stage]=true;
				dg(a[x][i].stage,bj,t+a[x][i].t,'g');
			}
	}
	else{
		for(int i=0;i<roal[x].size();i++){
			dg(roal[x][i],bj,t+a[roal[x][i]][x].t,'c');
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int x,t;
			cin>>x>>t;
			stop save;
			save.stage=x;
			save.t=t;
			a[i].push_back(save);
			roal[x].push_back(i);
		}
	}
	while(q--){
		ans=1e18;
		cin>>start>>end;
		dg(1,empty,0,'g');
		cout<<ans+w[start]+w[end];
	}
	return 0;
} 
