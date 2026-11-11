#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int nxt[2000005];
int lst[2000005];
int pre[2000005];
int suf[2000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1,j=1;i<=n;i++){
			while(j<n && a[j+1]-a[i]<=d) j++;
			nxt[i]=j;
		}
		for(int i=n,j=n;i>=1;i--){
			while(j>1 && a[i]-a[j-1]<=d) j--;
			lst[i]=j;
		}
		for(int i=1;i<=n;i++){
			int j=lst[i];
			if(lst[j]==lst[j+1]) pre[i]=i-j+1;
			else pre[i]=i-j+1+(lst[j+1]-lst[j])+pre[lst[j]]-1;
		}
		for(int i=n;i>=1;i--){
			int j=nxt[i];
			if(nxt[j]==nxt[j-1]) suf[i]=j-i+1;
			else suf[i]=j-i+1+(nxt[j]-nxt[j-1])+suf[nxt[j]]-1;
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			int j=nxt[i];int l=nxt[j-2]+1,r=nxt[j-1];
			if(j-i<2) continue;
//			cout<<l<<' '<<r<<'\n';
//			for(int i=l;i<r;i++){
//				ans++;
//			}
			if(l>r) continue;
			long long mul=1;
			ans+=mul*(r-l);
			if(lst[j]==i && lst[j-1]==i) mul*=pre[i];
			if(nxt[j]==nxt[j-1]) mul*=suf[nxt[j]];
			ans+=mul;
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++){
//			cout<<lst[i]<<' '<<nxt[i]<<' '<<pre[i]<<' '<<suf[i]<<'\n';
			a[i]=pre[i]=suf[i]=lst[i]=nxt[i]=0;
		}
	}
}
/*
0 1
5 3
1 2 3 4 5
*/
