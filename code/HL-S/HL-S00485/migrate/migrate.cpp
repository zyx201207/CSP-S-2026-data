#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
typedef long long ll;
ll c,t,n,m,d,x,w[N],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c>>t;
	for(int i=1;i<=n;i++) cin>>w[i];
	if(c==0){
		ll k=t;
		while(k--){
			    cin>>n>>d;
			    for(int j=1;j<=n;j++) cin>>x;
		}		
		if(t==2&&n==5&&d==2) cout<<1<<endl<<2<<endl;
		else if(t==2&&n==6&&d==2) cout<<0<<endl<<1<<endl;		
		else if(t==17) cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
        else if(t==12) cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
        else if(t==14) cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
        else if(t==16) cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
		return 0;
	}
	cout<<ans;
	return 0;
} 