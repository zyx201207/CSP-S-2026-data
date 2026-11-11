#include<bits/stdc++.h>
using namespace std;
ios::sync_with_stdin(0);
cin.tie(0);cout.tie(0);
struct tree{
	long long l,r,zz,yz;
}tr[500000];
long long find(int ks,int js,long long ans){
	if(ks==js) return ans+=tr[js].zz;
	if(tr[ks].l!=0) return find(tr[ks].l,js,ans+=tr[ks].zz);
	if(tr[ks].r!=0) return find(tr[ks].r,js,ans+=tr[ks].yz);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,t[500000],k,g1,z1,g2,z2,be,end;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++) cin>>t[i];
	for(int j=0;j<n;j++){
		cin>>k>>g1>>z1;
	    for(int i=2;i<2*k;i++){
	    	cin>>g2>>z2;
	    	if(tr[g1].l==0) tr[g1].l=g2,tr[g1].zz=z2;
	    	else tr[g1].r=g2,tr[g1].yz=z2;
	    	g1=g2,z1=z2;
		}
	}
	for(int i=0;i<q;i++) {
		cin>>be>>end;
		cout<<find(be,end,0)+t[be]+t[end];
	}
	return 0;
}
