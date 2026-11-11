#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll c,n,m,d,q;
struct l{
	ll k,a[1000],t[1000];
};

struct R{
	ll l,r;
};
void dt(){
	cin>>c>>n>>m>>d>>q;
	ll w[m+3];
	l s[n+2];
	R r[q+3];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>s[i].k;
		for(int j=1;j<=s[i].k;j++){
			cin>>s[i].a[j]>>s[i].t[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>r[i].l>>r[i].r;
	}
	
	ll nm=0;
	for(int i=1;i<=n;i++){
		nm+=s[i].k;
	}
//	ll ci=1;
	ll lj[m+3]={0};
//	ll j=1;
	for(int i=1,j=1,ci=1;i<=nm;i++){
		if(j<=s[ci].k){
			lj[s[ci].a[j]]++;
			j++;
		}
		else{
			ci++;
			j=1;
			lj[s[ci].a[j]]++;
			j++;
		}
	}
	
	ll jx[n+3];
	for(int i=1,j=1;i<=m;i++){
		if(lj[i]>=2){
			jx[j]=i;
			j++;
		}
	}
	ll ans[q+2]={0};
	for(int i=1;i<=q;i++){
		ans[i]+=w[r[i].l]+w[r[i].r];
	}
//	for(int i=1,j=1,ci=1;i<=nm;i++){
//		if(i!=2){
//			ans+=s[ci].t[j];
//		}
//		else
//	}
	
	cout<<ans;
	
	
}



int main (){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	dt();
	
	return 0;
}
