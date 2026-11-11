#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,ans;
ll d,a[2000006];
int dfs(int st,int tar,int cnt){
//	cout<<1;
	if(tar<cnt) return 0;
	if(st==n){
		if(tar==cnt) return 1;
		return 0;
	}
	int res=0;
	for(int i=st+1;i<=n;i++){
		if(a[st]+d>=a[i]){
			res+=dfs(i,tar,cnt+1);
		}
	}
	return res;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
//			cout<<1;
			memset(a,0,sizeof a);
			for(int i=1;i<=n;i++) cin>>a[i];
			ll k=a[2]-a[1];
//			cout<<k<<' '<<d<<' ';
			if(k>=d||k==0) cout<<0<<endl;
			else if((d/k)>=n) cout<<0<<endl;
			else cout<<max(0ll,(n-2*(d/k)+1))<<endl;
		}
		return 0;
	}
	else if(c==13||c==14){
		while(t--){
			cin>>n>>d;
			memset(a,0,sizeof a);
			for(int i=1;i<=n;i++) cin>>a[i];
			cout<<1;
		}
	}
	while(t--){
		cin>>n>>d;
		ans=0;
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int st=1;st<=n;st++){
			for(int ed=st+1;ed<=n;ed++){
//				cout<<ed<<' ';
				int mn=n+10,cnt=0;
				int l=st;
				for(int k=st;k<=ed;){
					ll pp=lower_bound(a+st,a+ed+1,a[l]+d)-a;
					if(k==pp) break;
//					cout<<pp;
					k=pp,cnt++;
				}
				int tot=dfs(st,cnt,0);
//				cout<<ed;
				if(tot==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
