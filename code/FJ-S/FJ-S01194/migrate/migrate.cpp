#include<bits/stdc++.h>
using namespace std;
long long a[5005],v[5005][5005],to[5005][5005],cnt[5005][5005],b[5005];
vector<int> q[5005];
queue<int> p;
int main(){
   freopen("migrate.in","r",stdin);
   freopen("migrate.out","w",stdout);
	long long n,d,i,c,t,j,k,ans=0;
	cin>>c>>t;
	while(t--){
		memset(q,0,sizeof(q));
		ans=0;
		cin>>n>>d;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					q[i].push_back(j);
					q[j].push_back(i);
				}
			}
		}
		for(i=1;i<=n;i++){
			memset(b,0,sizeof(b));
			memset(v,-1,sizeof(v));
			p.push(i);
			b[i]=1;
			while(!p.empty()){
				int top=p.front();
				p.pop();
				for(j=0;j<q[top].size();j++){
					if(b[q[top][j]]!=0){
						if(v[i][j]==-1) cnt[i][j]++,v[i][j]=b[top]+1;
						else if(v[i][j]==b[top]+1) cnt[i][j]++;
						continue;
					}
					p.push(q[top][j]);
					if(v[i][j]==-1) cnt[i][j]++,v[i][j]=b[top]+1;
					else if(v[i][j]==b[top]+1) cnt[i][j]++;
					b[q[top][j]]=b[top]+1;
				}
			}
		}
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				if(cnt[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
