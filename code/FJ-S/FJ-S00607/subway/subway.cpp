#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[5005],t[5005][505],mark[5005],ans,a1[5000][5000],sbn;
vector<int> lin[505];
int isin(int x,int l){
	if(x==lin[l][(lower_bound(lin[l].begin(),lin[l].end(),x)-lin[l].begin())]){
		return 1;
	}
	return 0;
}
void f(int x,int y,int nw){
	
	if(mark[x]) return;
	if(x==y){
		if(ans==0)ans=nw;
		ans=min(ans,nw);
		return;
	}
	if(nw>=a1[sbn][x] && a1[sbn][x]>0)return;
	a1[sbn][x]=nw;
	mark[x]=1;
	for(int i=1;i<=n;i++){
		if(isin(x,i)){
			for(int j=0;j<lin[i].size();j++){
				if(lin[i][j]==x)continue;
				f(lin[i][j],y,nw+t[lin[i][j]][i]+t[x][i]);
			}
		}
	}
	mark[x]=0;
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
		for(int j=1;j<=k;j++){
			int li,tim;
			cin>>li>>tim;
		    lin[i].push_back(li);
		    t[li][i]=tim;
		}
		sort(lin[i].begin(),lin[i].end());
	}
	for(int i=1;i<=q;i++){
		ans=0;
        for(int j=1;j<=m;j++){
        	mark[j]=0;
		}
		int x,y;
		cin>>x>>y;
		sbn=x;
	    f(x,y,w[x]+w[y]);
	    cout<<ans<<"\n";
	}
	return 0;
}
