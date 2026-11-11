#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
int c,t,n,d,a[200000];
int f[200001];
int ans;
void solve(int pts){
	ans=0;
	cin>>n>>d;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int s=0;s<n;++s){
		memset(f,0,sizeof(f));
		int x=upper_bound(a,a+n,a[s]+d)-a;
		++f[s+1],--f[x];
		for(int i=s+1;i<n;++i){
			f[i]+=f[i-1];//'"'"'"'"'"'"'"'"'"'"'"''"'"'"'"'"'"'"'"'"'"'"'
			if(f[i]==2)++ans;
			if(f[i]>2)break;
			int x=upper_bound(a,a+n,a[i]+d)-a;
			f[i+1]+=f[i];
			f[x]-=f[i];
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","rb",stdin);
	freopen("migrate.out","wb",stdout);
	cin>>c>>t;
	while(t--)solve(30);
	return 0;
}
