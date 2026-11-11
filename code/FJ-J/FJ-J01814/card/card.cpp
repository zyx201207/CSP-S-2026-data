#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,a[500005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans[300005];
	for(int i=1;i<=n;i++){
		queue<long long> q[300005];
		bool pd[300005];
		long long mi=n+1,ma=0;
		for(long long j=i;j<=n;j++){
			if(!q[a[j]].empty()){
				mi=min(q[a[j]].front(),mi);
				ma=max(ma,j);
			}
			else{
				q[a[j]].push(j);
			}
		}
		long long anss=0;
		for(int j=i;j<=mi;j++){
			if(pd[a[j]]==0){
				anss++;
			}
			pd[a[j]]=1;
		}
		for(int j=ma;j<=n;j++){
			if(pd[a[j]]==0){
				ans[a[j]]++;
			}
			pd[a[j]]=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
