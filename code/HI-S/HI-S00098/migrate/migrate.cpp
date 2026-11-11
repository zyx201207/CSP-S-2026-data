#include<bits/stdc++.h>
#define cc pair<long long,long long>
#define int long long
using namespace std;
priority_queue<cc,vector<cc>,greater<cc> > q;
int c,t;
int a[2000005];
vector<int> v[2000005];
int d[2000005],f[2000005],cnt[2000005];
signed dj(int x){
	memset(f,0,sizeof(f));
	memset(d,0x3f,sizeof(d));
	memset(cnt,0,sizeof(cnt));
	d[x]=0;
	q.push({0,x});
	while(!q.empty()){
		cc h=q.top();
		q.pop();
		int dis=h.second;
		int len=h.first;
		if(f[dis]==1) continue;
		else f[dis]=1;
		for(int j=0;j<v[dis].size();j++){
			int to=v[dis][j];
			if(d[to]==len+1){
				cnt[to]++;
			}
			if(d[to]>len+1){
				d[to]=len+1;
				q.push({d[to],to});
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int sum=0;
		int n,d; cin>>n>>d;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			v[i].clear();
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(a[j]-a[i])<=d) {
					v[i].push_back(j);
				}
			} 
		}
		for(int i=1;i<=n;i++){
			dj(i);
			for(int j=1;j<=n;j++){
				if(cnt[j]==1){
					sum++; 
				}
			} 
		}
		cout<<sum<<endl;
	}
	return 0;
}
