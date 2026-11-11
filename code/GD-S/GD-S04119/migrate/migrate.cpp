#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int c,t,n,nxt[2000006],num,b[2000006],rnxt[2000006],st=1;
ll d,a[2000006],ans,w[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
//	c=11;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			nxt[i]=i;
		}
		if(c==11||c==12){
			ll D=a[2]-a[1];
			ll k=d/D;
			if(k<=1)cout<<"0\n";
			else cout<<max(0ll,1ll*n-2*k+1)<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			nxt[i]=max(nxt[i-1],nxt[i]);
			while(nxt[i]<n&&a[nxt[i]+1]-a[i]<=d)nxt[i]++;
		}
		for(int i=1;i<=n;i++){
			w[i]=0;
			int ni=nxt[i],nni=nxt[nxt[i]];
			if(nni==ni||ni==i)continue;
			int j=ni-1,k=ni-2;
			if(j==i)continue;
			if(k<=i)k=i;
			int nj=nxt[j],nk=nxt[k];
			w[i]=nj-nk;
			b[i]=j;
		}
		for(int i=n;i>=1;i--){
			rnxt[nxt[i]]=i;
		}
		ans=0;
		for(int i=1;i<=n;i++){
			if(w[i]){
				int t=1;
				for(int g=i-1;g>=st;g--){
					if(nxt[g]>=b[i])continue;
					if(g!=i-1&&nxt[g]>=g+1)nxt[g]=nxt[g+1];
					if(nxt[g]<i)break;
					t++;
				}
				ans+=1ll*w[i]*t;
				st=nxt[b[i]]+1;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/
