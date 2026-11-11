#include <bits/stdc++.h>
using namespace std;
long long ans=-9999,n,d,cnt=0,res=0;

void dfs(int st,int ed,int sp,vector<long long>&x){
	if(st=ed){
		if(ans==sp){
			cnt=1;
			return;
		}else if(sp<ans){
			cnt=0;ans=sp;
			return;
		}
	}
	for(int i=st+1;i<=ed;i++){
		if(x[i]-x[st]<=d){
			sp+=x[i]-x[st-1];
			dfs(i,ed,sp,x);
		}
	}
}

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;cin>>c>>t;
	while(t--){
		cin>>n>>d;
		vector<long long>x(n+1,0);
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				ans=-9999,cnt=0;
				dfs(i,j,0,x);
				if(cnt=1)res++;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
