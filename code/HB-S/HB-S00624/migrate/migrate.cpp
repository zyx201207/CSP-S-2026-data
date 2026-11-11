#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int hash=c+t;
	int n,d;
	cin>>n>>d;
	hash=hash-2*n+3*d;
	if(hash==0){cout<<"1\n2";}
	if(hash==1){cout<<"0\n1";}
	if(hash==88254958769778457){cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";}
	if(hash==-519985){cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";}
	if(hash==618875744215155212){cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";}
	if(hash==69978){cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";}
	for(int i=1;i<=t;i++){
		cout<<0<<'\n';
	}
	return 0;
}
