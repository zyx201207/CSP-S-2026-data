#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e6+10;
int c,t,n,p[maxn],s[maxn];
ll d,x[maxn],a[maxn],b[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		memset(p,0,sizeof(p));
		memset(s,0,sizeof(s));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int now=d,j=1;
		for(int i=1;i<n;i++){
			now-=x[i+1]-x[i];
			while(j<=i&&now<0){
				now+=x[j+1]-x[j];
				p[j]=i;
				j++;
			}
			p[j]=max(p[j],i+1);
		}
		for(int i=1;i<=n;i++){
			if(!p[i])p[i]=n;
			a[i]=b[i]=1;
		}
		for(int i=n;i>=1;i--){
			s[p[i]]=i;
		}
//		for(int i=1;i<=n;i++)cout<<p[i]<<' ';
//		cout<<'\n';
		for(int i=1;i<=n;i++){
			if(a[p[i]]==1)a[p[i]]+=a[i];
			else a[p[i]]++;
		}
		for(int i=n;i>=1;i--){
			if(b[s[i]]==1)b[s[i]]+=b[i];
			else b[i]++;
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			int l1=i,r1=p[i],l2=p[i]-1,r2=p[l2];
			if(l1>=l2||r1>=r2||p[r1-2]>=r2)continue;
			ans+=a[l1]*b[r2];
		}
		for(int i=n;i>=1;i--){
			int r2=i,l2=s[i],r1=l2+1,l1=s[i];
			if(l1>=l2||r1>=r2||s[l2+2]<=l1)continue;
			ans+=a[r2]*b[l1];
		}
		cout<<ans<<'\n';
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
