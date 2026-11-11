#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	for(int T=1;T<=t;T++){
		int n,d,cnt=0,cha;
		cin>>n>>d;
		int a[2000005];
		bool f1=1,f2=0;
		cin>>a[1]>>a[2];
		cha=a[2]-a[1];
		for(int i=3;i<=n;i++){
			cin>>a[i];
			if(cha!=a[i]-a[i-1]) f1=0;
		}
		if(f1){
			for(int i=2;i<=4;i++) if(a[i]-a[i-1]>d) f2=1;
		if(f2) {cout<<0;break;}
		int nn=n;
		for(int l=1;l<=n-3;l++){
			for(int r=l+3;r<=n&&r<=nn;r++){
				if(a[r]-a[r-1]>d) {nn=r;break;}
				if((a[r]-a[l])%d==0) break;
				if((r-l+1)/d==2) cnt++;
		}
		
	}
	cout<<cnt<<endl;
}
else cout<<0<<endl;
}
		/*for(int i=2;i<=4;i++) if(a[i]-a[i-1]>d) f=1;
		if(f) {cout<<0;break;}
		int nn=n;
		for(int l=1;l<=n-3;l++){
			for(int r=l+3;r<=n&&r<=nn;r++){
				if(a[r]-a[r-1]>d) {nn=r;break;}
				if((r-l+1)%d==0) break;
				int cmt=0,dd=(r-l+1)/d;
				for()*/return 0;
			}
		
	
	


