#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,h=0;
ll a[500005];
ll b[300005];
struct op{
	ll l;
	ll r;
};
op l[500005];
ll u[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(u,0,sizeof(u));
		for(int j=1;j<=n;j++){
			l[j].l=0;
			l[j].r=0;
		}
		l[h].r=i;
		l[i].l=h;
		for(int j=i;j<=n;j++){
			l[j].r=j+1;
			l[j+1].l=j;
		}
		for(int j=i;j<=n;j++){
			if(!u[a[j]]){
				u[a[j]]=j;
				//cout<<j<<"   ";
			}else{
				ll v=u[a[j]];

				ll lf=l[v].l;
				ll t=l[lf].r;
				while(t!=j){
					u[a[t]]=0;
					t=l[t].r;
				}
				u[a[j]]=j;
				l[lf].r=j;
				l[j].l=lf;
				//cout<<lf<<" ";
			}
		}
		//cout<<'\n';
		ll t=l[h].r;
		while(1){
			//cout<<t<<" ";
			b[a[t]]++;
			t=l[t].r;
			if(t==n+1){
				break;
			}
		}
		//cout<<'\n';
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}

