#include<bits/stdc++.h>
#define int long long
#define f(i,x,n,y) for(int i=x;i<=n;i+=y)
#define f1(i,x,n,y) for(int i=x;i>=n;i-=y)
#define pair pair<int,int>
using namespace std;
const int N=2e6+5;
int T,t,n,m,k,k1,l,r,ans,sum,cnt,a[N],b[N];
string s1;
void dfs(int x,string s){
	if(x==r){
		if(s.size()<k1){
			k1=s.size();
			s1=s;
			cnt=1;
		}else if(s.size()==k1){	
			if(s1!=s)cnt++;
		}
		return;
	}
	if(!b[x]||t){
		t=1;
		return;
	}
	for(int i=1;i<=b[x];i++){
		dfs(x+b[x],s+char(48+i));
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	while(cin>>t>>T){
		while(T--){
			cin>>n>>m;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			for(int i=1;i<=n;i++){
				k=upper_bound(a+1,a+1+n,a[i]+m)-a-1;
				b[i]=k-i;
			}
			for(int i=1;i<=n;i++){
				for(int j=i+3;j<=n;j++){
					l=i,r=j,t=0,k1=1e9,cnt=0,s1="";
					dfs(l,"");
					if(cnt==2){
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}
		
	}


	return 0;
}

