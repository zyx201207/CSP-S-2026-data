#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long a[2000005];
long long use[2000005];
queue<long long> q;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t>0){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		q.push(1);
		while(!q.empty()){
			for(int i=1;i<=n;i++){
				use[i]=0;
			}
			while(!q.empty()){
				int x=q.front();
				q.pop();
				use[x]++;
			}
			for(int i=1;i<=n;i++){
				if(use[i]==2){
					ans++;
				}
				if(use[i]){
					for(int j=i+1;(a[j]<=(a[i]+d))&&(j<=n);j++){
						q.push(j);
					}
				}
			}
		}
		cout<<ans<<endl;
		t-=1;
	}
	return 0;
}
