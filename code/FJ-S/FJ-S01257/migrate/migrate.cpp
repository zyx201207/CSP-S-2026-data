#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int a[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		queue<int> q;
		for(int i=1;i<=n;i++){
			while(!q.empty()&&a[i]-a[q.front()]>=2*d) q.pop();
			q.push(i);
			if(q.size()==4&&a[q.back()]-a[q.front()]>d){
				ans++;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

