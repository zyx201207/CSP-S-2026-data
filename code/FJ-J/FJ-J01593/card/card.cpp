#include<bits/stdc++.h>
using namespace std;
long long a[500001],b[300001];
bool c[500001];
stack<long long> q;
void find1(long long t){
	for(long long i=1;;i++){
		c[q.top()]=false;
		if(q.top()==t){
			q.pop();
			return ;
		}
		q.pop();
	}
	cout<<"WRONG!";
	return ;
}
void csh(){
	for(long long i=1;i<=300000;i++) b[i]=0;
}
void qingkong(long long maxn){
	for(long long i=1;i<=maxn+1;i++){
		if(!q.empty()) q.pop();
		c[i]=false;
	}
	while(!q.empty()) q.pop();
	maxn=-0x7f;
	return ;
}
int main(){
	csh();
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long n,m,maxn=500001;
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	for(long long i=1;i<=n;i++){
		qingkong(maxn);
		for(long long j=i;j<=n;j++){
			if(c[a[j]]) find1(a[j]);
			c[a[j]]=true;
			maxn=max(maxn,a[j]);

			q.push(a[j]);
		}
		while(!q.empty()) if(m>=q.top()){
				b[q.top()]++;
				q.pop();
			}
	}
	for(long long i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}
