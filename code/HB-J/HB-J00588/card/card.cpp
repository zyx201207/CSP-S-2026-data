#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[1000005];
long long b[1000005];
int c[1000005];
long long ans[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long now=1;
	while(now<=n){
		stack<int>v;
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(long long i=now;i<=n;i++){
			if(c[a[i]]){
				for(long long i=1;i<=n-now-c[a[i]];i++){
					v.pop();
				}
			}else{
				v.push(a[i]);
				c[a[i]]=i;
			}
		}
		while(!v.empty()){
			b[v.top()]++;
			v.pop();
		}
		for(long long i=1;i<=m;i++){
			ans[i]+=b[i];
		}
		now++;
	}
	for(long long i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
