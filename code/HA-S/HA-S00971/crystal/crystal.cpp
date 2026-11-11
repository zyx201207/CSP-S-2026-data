#include<bits/stdc++.h>
#define int long long
using namespace std;
int dn,dm,dns=1,d[500086];
int dc[500050],dum[500050];
bool checkd(int dx){
	int dlag,dns1,id=dn;
	for(int i=1;i<=dn;i++){
		dc[i]=d[dx]-d[i];
		if(dc[i]>=0) dlag=1;
	}
	if(dlag==0) return 1;
	dlag=0;
	for(int i=1;i<=dn;i++){
		if(dc[i]<0){
			id=i-1;
			break;
		}
		dum[i]=dum[i-1]+dc[i];
	}
	for(int i=1;i<=id;i++){
		int dl1=i,dr1=id;
		while(dl1<=dr1){
			if(dl1==dr1){
				if(dum[dl1]>dm) break;
			}
			int did1=(dl1+dr1)/2;
			if(dum[did1]-dum[i-1]<=dm){
				dl1=did1+1;
				dns1=did1;
			}
			else dr1=did1-1;
		}
		if(dns<=dns1-i+1){
			dns=dns1-i+1;
			dlag=1;
		}
	}
	if(dlag) return 1;
	else return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>dn>>dm;	
	for(int i=1;i<=dn;i++) cin>>d[i];
	if(dn<=20000){
			sort(d+1,d+1+dn);
			int dl=1,dr=dn;
		for(int i=2;i<=dn-1;i++){
			checkd(i);
		}
		cout<<dns<<'\n';
		return 0;
	}
	else{
		cout<<dn/2+1;
	}
	return 0;
}
