#include<bits/stdc++.h>
using namespace std;
int n,m;
bool f[200005];
long long p=1,ans,a[200005],c[200005];

void wcl(int x,int cnt,long long sum){
	if(sum<ans) return;
	if(cnt==m){
		ans=max(ans,sum);
		return;
	}
	if(x>n) return;
	if(!f[x]){
		f[x]=1;
		wcl(x+1,cnt+1,sum&a[x]);
		wcl(x+1,cnt,sum);
		f[x]=0;
	}
	else{
		wcl(x+1,cnt,sum);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		p&=a[i];
	}
	if(m==n-1){
		for(int i=1;i<=n;++i){
			ans=max(ans,p|a[i]);
		}
	}
	else{
		for(int i=1;i<=n;++i){
			f[i]=1;
			wcl(i,1,a[i]);
			f[i]=0;
		}
	}
	cout<<ans;
	return 0;
}
