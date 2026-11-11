#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t,n,d,k,ans,bj[N],cl[N],dis[N],len1,len2,as1,as2;
vector<int>v[N];
void ds(int x,int f){
	int len=v[x].size();
	for(int i=0;i<len;i++){
		if(v[x][i]==f||!bj[v[x][i]])continue;
		cl[v[x][i]]=cl[x];
		ds(v[x][i],x);
	}
	return;
}
void df(int x,int f,int tp,int sd){
	if(bj[x])dis[tp]=min(dis[tp],sd);
	int len=v[x].size();
	for(int i=0;i<len;i++){
		if(v[x][i]==f)continue;
		df(v[x][i],x,tp,sd+1);
	}
	return;
}
int check(){
	for(int i=1;i<=n;i++)cl[i]=0;
	int ly=0,ans=0;
	for(int i=1;i<=n;i++){
		if(!bj[i])continue;
		if(!cl[i])cl[i]=++ly,ds(i,0);
	}
	if(ly>2)return n;
	for(int i=1;i<=n;i++){
		dis[i]=n;
		df(i,0,i,0);
		ans=max(ans,dis[i]);
	}
	return ans;
}
void dfs(int x,int gs){
	if(x==n+1){
		if(gs!=d)return;
		ans=min(ans,check());
		return;
	}
	bj[x]=1;
	dfs(x+1,gs+1);
	bj[x]=0;
	dfs(x+1,gs);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(n<=10){
			for(int i=1;i<=n;i++)v[i].clear();
			for(int i=1;i<n;i++){
				int x,y;
				cin>>x>>y;
				v[x].push_back(y);
				v[y].push_back(x);
			}
			ans=n;
			dfs(1,0);
			cout<<ans<<"\n";
		}else{
			for(int i=1;i<=n;i++)v[i].clear();
			for(int i=1;i<n;i++){
				int x,y;
				cin>>x>>y;
				v[x].push_back(y);
				v[y].push_back(x);
			}
			if(n==d){
				cout<<"0\n";
				continue;
			}
			if(d>=n/2){
				cout<<"1\n";
			}
			n/=2;
			len1=n/2;
			len2=(n+1)/2;
			as1=d/2;
			as2=(d+1)/2;
			cout<<max((len1-as1+1)/2+1,(len2-as2+1)/2+1)<<"\n";
		}
	}
	return 0;
}
