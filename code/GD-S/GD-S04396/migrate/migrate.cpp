#include<bits/stdc++.h>

#define fr(i,l,r) for(int i=(l);i<=(r);i++)
#define fo(i,l,r) for(int i=(l);i<(r);i++)
#define fd(i,r,l) for(int i=(r);i>=(l);i--)

#define LL long long

using namespace std;

int Tid;

const int N=2e6+5;

int n;
LL D,a[N];

int f[N],g[N];

int pr[N],sf[N];
int tp[N],ts[N],p[N],s[N];

LL Ans;

void Main(){

	fr(i,0,n+1){
		a[i]=0;
		pr[i]=sf[i]=0;
		tp[i]=ts[i]=0;
		p[i]=s[i]=0;
	}
	Ans=0;

	cin>>n>>D;
	fr(i,1,n){
		cin>>a[i];
	}

	pr[n+1]=n+1;
	fd(i,n,1){
		pr[i]=min(pr[i+1],i);
		while(pr[i]>1&&a[i]-a[pr[i]-1]<=D)pr[i]--;
		if(pr[i]!=i)s[pr[i]]++;
	}
	fr(i,1,n){
		sf[i]=max(sf[i-1],i);
		while(sf[i]<n&&a[sf[i]+1]-a[i]<=D)sf[i]++;
		if(sf[i]!=i)p[sf[i]]++;
	}

	fr(i,1,n){
		tp[i]=p[i]+1;
		if(pr[i]!=i&&sf[pr[i]]==i)tp[i]+=tp[pr[i]]-1;
	}
	fd(i,n,1){
		ts[i]=s[i]+1;
		if(sf[i]!=i&&pr[sf[i]]==i)ts[i]+=ts[sf[i]]-1;
	}

	if(Tid<=6){
		fr(x,1,n){
			fr(i,1,n)f[i]=n,g[i]=0;
			f[x]=0;g[x]=1;
			fr(i,x,n){
				fr(j,i+1,n){
					if(a[j]-a[i]>D)break;
					if(f[i]+1<f[j]){
						f[j]=f[i]+1;
						g[j]=0;
					}
					if(f[i]+1==f[j]){
						g[j]=min(g[j]+g[i],10);
					}
				}
			}
			fr(i,x,n){
				if(g[i]==2){
					Ans++;
				}
			}
		}
	}
	else if(Tid<=10){
		fr(x,1,n){
			fr(y,sf[x]+1,n){
				if(sf[x]==pr[y]+1){
					int sx=(pr[sf[x]-1]==x)?tp[x]:1;
					int sy=(sf[sf[x]]==y)?ts[y]:1;
					Ans+=1ll*sx*sy;
				}
			}
		}
	}
	else{
		fr(x,1,n){
			int z=sf[x];
			int sx=(pr[z-1]==x)?tp[x]:1;
			Ans+=1ll*sx*(s[z-1]-(pr[z]==z-1));
			int y=sf[z];
			if(y>z&&pr[y]==z-1)Ans+=1ll*sx*(ts[y]-1);
		}
	}

	cout<<Ans<<"\n";

	return;
}

int main(){

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	ios::sync_with_stdio(false),cin.tie(nullptr);

	cin>>Tid;
	int Test=1;
	cin>>Test;
	while(Test--)Main();

	return 0;
}