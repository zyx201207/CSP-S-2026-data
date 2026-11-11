#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],vis[500005];
stack<long long>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++)vis[j]=0;
		while(!s.empty())s.pop();
		for(long long j=i;j<=n;j++){
			if(vis[a[j]]){
				while(1){
					long long t=s.top();
					s.pop();
					vis[t]--;
					if(t==a[j]){
						break;
					}
				}
			}
			vis[a[j]]++;
			s.push(a[j]);
		}
		for(long long j=1;j<=m;j++){
			if(vis[j]){
				b[j]++;
			}
		}
	}
	for(long long j=1;j<=m;j++){
		cout<<b[j]<<" ";
	}
	return 0;
}
