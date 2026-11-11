#include<bits/stdc++.h>
using namespace std;
long long a[200010],e,vis[200010][50],ans;
int r,n,m,mx,sis[50],ttt;
vector<long long>vt[50];
void f(long long x,int t){
	int c[50],e=0;
	while(x>=1){
		c[++e]=x%2;
		x/=2;
		mx=max(mx,e);
	}
	for(int i=1;i<=e;i++){
		if(c[i]==1)vt[i].push_back(t);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f(a[i],i);
	}
	for(int i=mx;i>=1;i--){
		if(int(vt[i].size())>=m){
			r=max(r,i);
			for(auto y:vt[i]){
				
				if(vis[y][r]==1||i==r){
					vis[y][i]=1,sis[i]++;
				}
			}
		}
	}
	for(int i=1;i<=mx;i++){
		if(sis[i]>=m){
			ttt=i;
		}
	}
	int f=0;
	for(auto y:vt[ttt]){
		if(vis[y][ttt]==1&&f<m){
			if(ans==0)ans=a[y];
			else ans&=a[y];
			f++;
		}
	}
	cout<<ans;
	return 0;
}
