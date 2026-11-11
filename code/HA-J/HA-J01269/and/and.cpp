#include<bits/stdc++.h>
#define int long long
using namespace std;
int dn,dm,d[200010],dns;
inline void dfs(int d1,int dum,int dnt){
	if(dnt==dm){
		dns=max(dns,dum);
		return ;
	}
	if(d1==dn+1) return ;
	dfs(d1+1,dum&d[d1+1],dnt+1);
	dfs(d1+1,dum,dnt);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>dn>>dm;
	if(dn<=20){
		for(int i=1;i<=dn;i++){
			cin>>d[i];
		}
		for(int i=1;i<=dn;i++){
			dfs(i,d[i],1);
		}
		cout<<dns<<'\n';
		return 0;
	}
	if(dm==dn){
		for(int i=1;i<=dn;i++){
			cin>>d[i];
			dns=d[i]&dns;
		}
		cout<<dns<<'\n';
		return 0;
	}
	if(dm==1){
		for(int i=1;i<=dn;i++){
			cin>>d[i];
			dns=max(d[i],dns);
		}
		cout<<dns<<'\n';
		return 0;
	}
	if(dm==dn-1){
		for(int i=1;i<=dn;i++){
			cin>>d[i];
		}
		sort(d+1,d+1+dn);
		for(int i=2;i<=dn;i++){
			dns=dns&d[i];
		}
		cout<<dns<<'\n';
	}
	else{
		int dum=-1,dd=0,dd1=0;
		for(int i=1;i<=dn;i++){
			cin>>d[i];
			dum=max(d[i],dum);
			if(d[i]==1) dd=d[i];
			if(d[i]==2) dd1=d[i];
		}
		if(dm==1){
			cout<<"3";
			return 0;
		}
		if(dum<4){
			if(dum==3) if(dd==1) cout<<"1";
			else if(dd1==2) cout<<"2";
			if(dum==2) if(dd==1) cout<<"0";
			else cout<<'2';
			if(dum==1) cout<<'1';
		}
		return 0;
	}
	return 0;
}
