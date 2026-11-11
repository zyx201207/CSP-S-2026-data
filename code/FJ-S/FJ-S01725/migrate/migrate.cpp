#include<bits/stdc++.h>
using namespace std;
int n,c,t;
long long d,x[2000100],ans;
long long nxt[2000100],pre[2000100],nxt2[2000100],pre2[2000100];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n<=5000){
			ans=0;
			for(int i=1;i<=n;i++){
				pre[i-1]=0;
				for(int j=i;j<=n;j++) nxt[j]=1e17,pre[j]=0;
				nxt[i]=0;pre[i]=1;
				for(int j=i+1;j<=n;j++){
					int pa=lower_bound(x+i,x+1+n,x[j]-d)-x;
					if(pa==n+1) break;
					int pb=upper_bound(nxt+pa,nxt+1+n,nxt[pa])-nxt-1;
					nxt[j]=nxt[pa]+1;pre[j]=pre[pb]-pre[pa-1];
					if(pre[j]==2) ans++;
//					if(i==1) cout<<j<<" "<<pa<<" "<<pb<<"\n";
					pre[j]+=pre[j-1];
				}
//				cout<<"\n";
			}
		}
		else{
			for(int i=n;i>=2;i--){
				int pa=upper_bound(x+1,x+1+n,x[i-1]+d)-x-1;
				int pb=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
	//			if(i==2){
	//				cout<<pa<<" "<<pb<<"\n";
	//			}
				pa=max(pa,i);
				if(pb==i||pa==pb) nxt[i]=0;
				else nxt[i]=pb-pa+nxt[pb];
				pa=max(pa,i+1);
				if(pa>=pb) nxt2[i]=0;
				else nxt2[i]=pb-pa+nxt[pb];
			}
			for(int i=1;i<n;i++){
				int pa=lower_bound(x+1,x+1+n,x[i+1]-d)-x;
				int pb=lower_bound(x+1,x+1+n,x[i]-d)-x;
				pa=min(pa,i);
				if(pb==i||pa==pb) pre[i]=0;
				else pre[i]=pa-pb+pre[pb];
				pa=min(pa,i-1);
				if(pa<=pb) pre2[i]=0;
				else pre2[i]=pa-pb+pre[pb];
			}
			for(int i=2;i<n;i++){
				if(i!=n&&x[i+1]-x[i]<=d&&x[i+1]-x[i-1]>d) nxt[i]--;
				if(i!=1&&x[i]-x[i-1]<=d&&x[i+1]-x[i-1]>d) pre[i]--;
			}
			ans=0;
			for(int i=1;i<n;i++){
				ans+=1ll*nxt2[i]*pre2[i+1];
			}
	//		for(int i=1;i<=n;i++) cout<<pre2[i]<<" ";cout<<"\n";
	//		for(int i=1;i<=n;i++) cout<<nxt2[i]<<" ";cout<<"\n";
			for(int i=1;i<=n;i++) pre[i]=nxt[i]=pre2[i]=nxt2[i]=0;
		}
		cout<<ans<<"\n";
	}
}
/*
0 1
10 22
0 7 14 21 28 35 42 49 56 63

*/