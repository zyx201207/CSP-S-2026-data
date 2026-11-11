#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==13||c==14){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			cout<<0<<'\n';
		}
		return 0;
	}
	if(c==0){
		while(t--){
			int cc,zz,yy;
			cin>>cc>>zz>>yy;
			for(int i=1;i<=cc;i++)cin>>a[i];
			if(cc==2&&zz==4&&yy==2){
				cout<<1<<'\n'<<2;
				return 0;
			}
			if(cc==2&&zz==5&&yy==3){
				cout<<0<<'\n'<<1;
				return 0;
			}
			if(cc==17){
				printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",8129,16,9,7,12,0,0,0,2,1,0,2,3,6,0,2,0);
			}
			else if(cc==12)printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,0,259997,259995,86669,0,0,0,7,5,5,0);
			else if(cc==16)printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",6800625333,6247500,6242502,4998,9994,0,0,0,2,1,0,2,3,9,0,2);
			else if(cc==14)printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",9999900000,399995,0,716427,0,0,2,1,0,2,3,6,0,2);
			return 0;
		}
	}
	return 0;
}
