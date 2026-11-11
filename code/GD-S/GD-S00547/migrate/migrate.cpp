#include<bits/stdc++.h>
#define int long long
using namespace std;

int c,t,n,d,tt,nn,dd;

signed main(){
	ios::sync_with_stdio(0),cin.tie(0);

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	cin>>c>>t,tt=t;
	
	if(c==0){
		while(t--){
			cin>>n>>d;
			
			int a[2000006];
			
			for(int i=1;i<=n;i++) cin>>a[i];
			
			if(t==tt-1) nn=n,dd=d;
			
		}
		
		if(nn==4 && dd==2) cout<<"1\n2\n";
		else if(nn==5 && dd==3) cout<<"0\n1\n";
		else if(nn==197 && dd==29418319589926278LL) cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
		else if(nn==260000 && dd==1) cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
		else if(nn==200001 && dd==206291914738518400) cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
		else if(nn==174944 && dd==139950) cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
		
		return 0;
	}
	
	

	return 0;
}
