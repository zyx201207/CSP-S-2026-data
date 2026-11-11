#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+10;
ll a[N],L[N],R[N],cl[N];
void solve(){
	int n;
	ll d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	int p=1;
	for(int i=1;i<=n;i++){
		while(a[p]+d<a[i])p++;
		L[i]=p;
		cl[L[i]]++;
	}
	p=n;
	for(int i=n;i>=1;i--){
		while(a[p]-d>a[i])p--;
		R[i]=p;
	}
//	for(int i=1;i<=n;i++)cout<<L[i]<<" "<<R[i]<<" "<<cl[i]<<"\n";
//	cout<<endl;
	ll ans=0;
	for(int s=1;s<=n;s++){
		if(R[s]==n)break;
		if(R[s]==s)continue;
		int id1=R[s],id2=-1,f1=1,f2=-1;
		if(R[s]>s+1)id2=R[s]-1,f2=1;
		while(1){
//			cout<<id1<<" "<<f1<<" "<<id2<<" "<<f2<<endl;
			if(id1==n || R[id1]==id1 || f1==-1)break;
			int nr=R[id1],nid1=-1,nid2=-1,nf1=-1,nf2=-1;
			if(f1==2 || f2==-1){
				if(f1==2)ans+=cl[id1];
				if(L[nr]==id1)nid1=nr,nf1=f1;
				if(nr>id1+1 && L[nr-1]==id1)nid2=nr-1,nf2=f1;
			}else{//only f1=f2=1
				if(f1+f2==2)ans+=cl[id2];
				if(L[nr]==id1){
					nid1=nr,nf1=f1;
					if(nr>id1+1 && L[nr-1]==id1)nid2=nr-1,nf2=f1;
					else if(nr>id1+1 && L[nr-1]==id2)nid2=nr-1,nf2=f1+f2;
				}else if(L[nr]==id2){
					nid1=nr,nf1=f1+f2;
					if(nr>id1+1 && L[nr-1]==id2)nid2=nr-1,nf2=f1+f2;
				}
			}
			id1=nid1,f1=nf1,id2=nid2,f2=nf2;
		}
//		cout<<s<<" "<<ans<<"\n";
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++)L[i]=R[i]=cl[i]=0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)solve();
	return 0;
}
