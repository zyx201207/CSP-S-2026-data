#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,d,x[2000005],cnt,use;

void dfs(ll st,ll ed,ll o,ll use){
	if(cnt>2) return;
	if(st==ed){
		if(o==use) cnt++;
		return;
	}
	for(ll i=st+1;i<=ed;i++){
		if(x[i]-x[st]>d) return;
		dfs(i,ed,o+1,use);
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int ans=0;
		bool flag=true;
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
			if(i>2 && x[i]-x[i-1]!=x[i-1]-x[i-2]){
				flag=false;
			}
		}
		if(flag){
			int xx=d/(x[2]-x[1]);
			if(xx<=1){
				cout<<"0\n";
			}else{
				cout<<max((ll)0,n-xx*2+1)<<"\n";
			}
			continue;
		}
		for(ll i=1;i<n;i++)
			for(int j=i+1;j<=n;j++){
				cnt=use=0;
				bool f=false;
				for(int k=i;k<j;){
					ll l=k;
					while(l<=j && x[l]-x[k]<=d) l++;
					if(x[l]-x[k]>d) l--;
					if(k==l){
						f=true;
						break;
					}
					k=l;
					use++;
				}
				if(f) continue;
				dfs(i,j,0,use);
				if(cnt==2){
					ans++;
				}
			}
		cout<<ans<<"\n";
	}
	return 0;
}
