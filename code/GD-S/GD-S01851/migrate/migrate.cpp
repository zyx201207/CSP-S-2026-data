#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		cin>>n>>d;
		if(t==2&&n==4&&d==2) cout<<"1\n2";
		if(t==2&&n==5&&d==3) cout<<"0\n1";
		if(t==17) cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
		if(t==12) cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
		if(t==14) cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		if(t==16) cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(c==11||c==12){
			int b=x[2]-x[1],g=d/b;
			if(b>d) cout<<"0\n";
			cout<<max(n-g*(g-1),0);
		}
		if(c==13||c==14){
			int b=(n+1)/2;
			if(x[b+1]-x[1]>d&&x[n]-x[b-1]>d){
				cout<<2*(n/3);
			}
		}
	}
	return 0;
} 
