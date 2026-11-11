#include<bits/stdc++.h>
using namespace std;
long long n,m,z;
long long a[500010];
long long sum[500010];
stack<long long>p;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool sf[300010];
		memset(sf,0,sizeof(sf));
		for(int j=i;j<=n;j++){
//			cout<<i;
			if(sf[a[j]]){
				while(p.top()!=a[j]){
					sf[p.top()]=0;
					p.pop();
				}
//				cout<<p.top();
				continue;
			}
			p.push(a[j]);
			sf[a[j]]=1;
		}
		while(!p.empty()){
			
			int q=p.top();
			sum[q]++;
			p.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
}
