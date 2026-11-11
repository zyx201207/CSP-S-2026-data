#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
pair<bool,int> depen[N];
struct{
	bool co;
	int nex;
}visit[M];
int a[N],ans[M],reduc[N];
int n,m,tme;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i--){
		if(!visit[a[i]].co)
			visit[a[i]].co=1;
		else
			depen[i]={1,visit[a[i]].nex};
		visit[a[i]].nex=i;
	}
	int k=0;
	for(int i=1;i<=n;i++){
		k-=reduc[i];
		tme=i-k;
		ans[a[i]]=max(ans[a[i]],tme);
		if(depen[i].first==1){
			k+=tme;
			reduc[depen[i].second]+=tme;
		}
	}
	
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
