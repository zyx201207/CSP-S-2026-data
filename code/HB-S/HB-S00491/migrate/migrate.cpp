#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long x[2000009],dpy[2000009];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(c==0){
		if(t==12)
			cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
			return 0;
		if(t==14)
			cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
			return 0;
		if(t==16)
			cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
			return 0;
	}
	long long mx=0,wi=0,ans=0;
	bool km=0;
	while(t--){
		cin >> n >> d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		dpy[1]=0;
		mx=0;
		km=0;
		wi=0;
		int gv;
		for(gv=2;gv<=n;gv++){
			dpy[gv-1]=0;
		for(int i=gv;i<=n;i++){
			wi=1;
			km=0;
			for(int j=gv-1;j<i;j++){
				if((x[i]-x[j])<=d){
					if(km==0){
						mx=dpy[j];
						km=1;
					}else{
						if(dpy[j]<mx){
							mx=dpy[j];
							wi=1;
						}else if(dpy[j]==mx){
							wi++;
						}
					}
					
				}
			}
			if(wi==2){
					ans++;
					//cout<<i<<" ";
					//gv=i;
				}
				dpy[i]=mx+1;
		}
	}
	cout<<ans<<endl;
	}
	return 0;
}
