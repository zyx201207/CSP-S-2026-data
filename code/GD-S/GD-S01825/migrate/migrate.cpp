#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long c,t,n,d,a[N],vis[N];
void fly(long long d,long long n){
	queue<long long>q;
	q.push(1);
	vis[1]=0;
	while(q.size()!=0){
		int now=q.front();
		q.pop();
		for(int i=now+1;i<=n;i++){
			if(abs(a[i]-a[now])<=d){
				q.push(i);
				vis[i]=min(vis[i],vis[now]+1);		
			}
			else break;
		}
	}
	return ;
}
long long check(long long d,long long n){
	queue<long long>q;
	long long ans=0;
	q.push(1);
	vis[1]=0;
	while(q.size()!=0){
		int now=q.front();
		q.pop();
		for(int i=now+1;i<=n;i++){
			if(abs(a[i]-a[now])<=d){
				q.push(i);
				if(vis[now]+1==vis[i])ans++;	
			}
			else break;
		}
	}
	return ans/2-1;	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		memset(vis,sizeof(vis),N);
		fly(d,n);
		cout<<check(d,n)<<"\n";
	}
	return 0;
}
