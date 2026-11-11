#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int a[N];
long long c,t,cnt;
long long k;
queue<long long>q;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long n,d;
	cin>>n>>d;
	q.push(1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]>d) q.push(i);   
	}
	q.push(n+1);
	while(!q.empty()){
		int s=q.front(); q.pop(); int e=q.front()-1;
		for(int u=s;u<=e;u++){
			for(int v=s+1;v<=e;v++){
				int k=a[v]-a[u];
				if(k>d&&k%d!=0) cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
