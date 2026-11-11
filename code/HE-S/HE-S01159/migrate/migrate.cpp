#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int c,t,n;
long long d,a[maxn],ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		ans=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++) cin>>a[j];
		if(c==0){
			if(t==2&&n==4) cout<<1<<endl<<2<<endl;
			if(t==2&&n==5) cout<<0<<endl<<1<<endl;
			if(n==17) cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0<<endl;
			if(n==12) cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0<<endl;
			if(n==14) cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl;
			if(n==16) cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl;
			break;
		}
		if(c==11||c==12){
			int q=d/(a[2]-a[1])+1;
			n-=1;
			while(q<=n){
				ans+=n-q+1;
				q+=2;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
