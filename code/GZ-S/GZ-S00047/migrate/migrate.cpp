//GZ-S00047 毕节七星关东辰实验学校 杜启民
#include<bits/stdc++.h>
#define ll long long
#define ul unsigned long long
#define heap priority_queue
using namespace std;

const int N=2e6+10;

int n,c;
ll d,x[N];
int nxt[N];
ll d1[N],d2[N];
ll ans[N];

void get_nxt(){

	for(int i=1;i<=n;i++){
		nxt[i]=(upper_bound(x+i+1,x+n+1,x[i]+d)-x-1);
	}

	return;
}

void solve(){

	cin>>n>>d;
	for(int i=1;i<=n;i++){cin>>x[i];}

	if(d==1){
		cout<<0<<'\n';
		return;
	}

	get_nxt();

	for(int i=n;i>=1;i--){
		d1[i]+=nxt[i]-i;
		if(nxt[nxt[i]]!=nxt[nxt[i]-1]){
			d1[i]+=(nxt[nxt[i]]-nxt[nxt[i]-1])+d1[nxt[nxt[i]]];
		}
		ll A=nxt[nxt[i]-1]-nxt[nxt[i]-2];
	//	ll B=d1[nxt[nxt[i]-1]];
		ll C=d2[nxt[nxt[i]]];
		d2[i]=A+C;
	//	cout<<A<<' '<<B<<' '<<C<<'\n';
		if(nxt[i]==n){d2[i]=0;}
	}

	ll sum=0;
	for(int i=1;i<=n;i++){
		sum+=d2[i];
	}

	cout<<sum<<'\n';

	for(int i=0;i<=n;i++){
		x[i]=d1[i]=d2[i]=nxt[i]=ans[i]=0;
	}n=0;

	return;
}

int main(){

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T=1;
	cin>>c;
	cin>>T;
	while(T--){solve();}

	return 0;
}
