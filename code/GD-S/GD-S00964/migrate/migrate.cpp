#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c;
ll t,n,m,a[200005],ans;
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar(); 
	} 
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	t=read();
	while(t--){
		n=read();
		m=read();
		ans=0;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				queue<ll> q;
				int ed;
				ll lat=a[i],cnt;
				if(a[j]-a[i]<=m)break;
				for(int k=i+1;k<=j;k++){
					if(a[k+1]-lat>m){
						lat=a[k];
						q.push(k);
						ed=k-1;
						continue;
					}
					if(k==j)q.push(j);
				}
				int s=q.front();
				while(!q.empty()){
					int no=q.front();
					q.pop();
					if(q.empty())break; 
					if(a[q.front()]-a[no-1]<=m){
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
