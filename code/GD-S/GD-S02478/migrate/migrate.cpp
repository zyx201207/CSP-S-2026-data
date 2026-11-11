#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN=2000000;
ll pos[MAXN+5];
ll l[MAXN+5],r[MAXN+5],gol[MAXN+5],gor[MAXN+5];//到这个点仅一条路径的左边/右边的点的数量 
ll el[MAXN+5],er[MAXN+5];
void work(){
	ll n;
	ll d,ans=0;
	cin>>n>>d;
	for(ll i=1;i<=n;i++){
		cin>>pos[i];
		l[i]=0;r[i]=0;
	}
	ll p=1,p2;
	for(ll i=1;i<=n;i++){
		while(pos[i]-pos[p]>d) p++;
		gol[i]=p;
		if(i!=1&&gol[i]==gol[i-1]) el[i]=el[i-1]+1;
		else el[i]=1;
	}
	p=n;
	for(ll i=n;i;i--){
		while(pos[p]-pos[i]>d) p--;
		gor[i]=p;
		if(i!=n&&gor[i]==gor[i+1]) er[i]=er[i+1]+1;
		else er[i]=1;
	}
	for(ll i=1;i<=n;i++){
		p=gol[i];p2=gor[p];
		if(p==i) l[i]=0;
		else if(p2==i){
			l[i]=l[p]+er[p];
		}
	}
	for(ll i=n;i;i--){
		p=gor[i];p2=gol[p];
		if(p==i) r[i]=0;
		else if(p2==i){
			r[i]=r[p]+el[p];
		}
	}
	for(ll i=4;i<=n;i++){//寻找结节 
		ll ml=gol[i],mr=ml+1;
		if(mr!=i) for(ll lef=gol[mr];lef<gol[mr+1]&&lef<ml;lef++){
			ll L=1,R=1;
			if(lef!=1){
				if(gor[lef-1]<ml){
					L+=l[lef];
				}
			}
			if(i!=n){
				if(gol[i+1]>mr){
					R+=r[i];
				}
			}
			ans+=L*R;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
//	freopen("D:\\csps-new\\down\\migrate\\migrate6.in","r",stdin);
//	freopen("D:\\csps-new\\down\\migrate\\migrate.out","w",stdout);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,T;
	cin>>c>>T;
	while(T--) work();
	return 0;
}
