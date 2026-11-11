#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,T,n;long long d;
long long a[N],v[N],t[N],w[N];
queue<int>q;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;long long ans=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=n;i>=1;i--){
			q.push(i);v[i]=0;t[0]=1,w[i]=1;
			for(int j=i-1;j>=1;j--){
				while(a[q.front()]-a[j]>d) t[v[q.front()]]-=w[q.front()],q.pop();
				if(q.empty()) break;
				if(t[v[q.front()]]==2) ans++;
				q.push(j);v[j]=v[q.front()]+1;
				w[j]=t[v[q.front()]];t[v[j]]+=w[j];
			}
			while(!q.empty()) t[v[q.front()]]-=w[q.front()],q.pop();
		}
		cout<<ans<<'\n';
	}
	return 0;
}
