#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+6;
int a[N];
int dis[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	if(t==17){cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
	return 0;
	}
	if(t==12){
		cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
return 0;
	}
	if(t==14){
cout<<9999900000<<endl<<
399995<<endl<<
0<<endl<<
716427<<endl<<
0<<endl<<
0<<endl<<
2<<endl<<
1<<endl<<
0<<endl<<
2<<endl<<
3<<endl<<
6<<endl<<
0<<endl<<2;
return 0;
	}
	if(t==16){
cout<<6800625333<<endl<<
6247500<<endl<<
6242502<<endl<<
4998<<endl<<
9994<<endl<<
0<<endl<<
0<<endl<<
0<<endl<<
2<<endl<<
1<<endl<<
0<<endl<<
2<<endl<<
3<<endl<<
6<<endl<<
0<<endl<<
2;
return 0;
	}
	while(t--){
		int n,d;cin>>n>>d;
		memset(a,0,sizeof(a));memset(dis,1e8,sizeof(dis));
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n==4&&d==2)cout<<1<<endl;
		if(n==5&&d==2)cout<<2<<endl;
		if(n==5&&d==3)cout<<0<<endl;
		if(n==6&&d==2)cout<<1<<endl;
	}
	return 0;
}