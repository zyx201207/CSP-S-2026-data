#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N=2e6+5;
int c,t,n,d;
int cnt;
int x[N];
inline int dfss(int s,int e){
	int p=s+1;
	if(x[s+1]-x[s]>d)return -1;
	while(p<e&&x[p]-x[s]<=d)
		p++;
	if(p==e&&x[p]-x[s]<=d)return 1;
	else return 1+dfss(p-1,e);
}
inline int dfs(int s,int e,int last){
	cnt++;
	if(cnt>=1000)return 0;
	int p=s+1,res=0;
	if(p==e)
		return 1;
	while(p<=e&&x[p]-x[s]<=d){
		res+=dfs(p,e,last-1);
		if(res>2)return 3;
		p++;
	}
	return res;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		cnt=0;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=0;
				int len=dfss(i,j);
				//cout<<i<<' '<<j<<' '<<len<<'\n';
				if(len<2)continue;
				if(dfs(i,j,len)==2)
					cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
