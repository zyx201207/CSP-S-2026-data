#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,ans=-123;
bool vis[200005];
void op(long long x,long long cnt){
	if(x>m){
		ans=max(ans,cnt);
		return ;
	}
	for(long long i=1;i<=n;i++){
		if(x==1){
			vis[i]=1;
			op(x+1,a[i]&a[i]);
			vis[i]=0;
		}
		if(vis[i]==0){
			vis[i]=1;
			op(x+1,cnt&a[i]);
			vis[i]=0;
		}
		
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	long long v=-10,l=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		v=max(v,a[i]);
		if(l!=0)l=a[i]&l;
		else l=a[i];
	}
	if(m==1){
		cout<<v;
		return 0;
	}
	if(m==n){
		cout<<l;
		return 0;
	}
	op(1,0);
	cout<<ans;
	return 0;
}
