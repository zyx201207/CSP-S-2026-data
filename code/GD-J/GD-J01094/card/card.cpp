#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200005
int n,k;
int val[N];
struct NUM{
	int v,num;
};
int ans[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>val[i];
	queue <NUM> q;
	for(int i=1;i<=n;i++){
		int cur=1;
		while(q.front().v!=val[i]&&cur<=n){
			if(val[i]==q.front().v){
				int m=q.front().num;
				q.pop();
				int t=-1;
				while(q.front().v!=t&&!(q.empty())){
					NUM f=q.front();
					q.pop();
					if(f.num>m){
						//cout<<f.v<<" "<<f.num-m<<"\n";
						q.push({f.v,f.num-m});
						if(t==-1) t=f.v; 
					} 
				}
				break;
			}
			q.push(q.front());
			q.pop();
			cur++;
		}
		q.push({val[i],i});
	}
	while(!q.empty()){
		ans[q.front().v]=q.front().num;
		q.pop();
	}
	for(int i=1;i<=k;i++) cout<<ans[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

