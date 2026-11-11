#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,s[200001],mod[31],NMAX,cnt;
bool vis[200001],recorded;
vector<ll>p;
vector<ll>record;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	mod[0]=1;
	NMAX=1;
	for(int i=1;i<=30;i++){
		mod[i]=mod[i-1]*2;
		NMAX+=mod[i];
	}
		for(int i=30;i>=0;i--){
		cnt=0;
		p.clear();
		for(int j=1;j<=n;j++){
			if((s[j]&mod[i])){
			cnt++;
			p.push_back(j);
			}
		}
		if(cnt==m){
			for(auto e:p){
				NMAX=(NMAX&s[e]);
			}
			cout<<NMAX;
			return 0;
		}
		if(cnt>m){
			for(auto e:p){
				vis[e]=1;
				record.push_back(e);
			}
			for(int j=1;j<=n;j++){
				if(vis[j]==0)	s[j]=0;
			}
			memset(vis,0,sizeof(vis));
			recorded=1;
		}
		if(i==0&&recorded==1){
			for(auto e:record){
				NMAX=(NMAX&s[e]);
			}
			cout<<NMAX; 
		}
	}
	return 0;
}
