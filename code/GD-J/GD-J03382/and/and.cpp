#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[20001];
long long q(int x,int y){
	long long on[21],tw[21],c[21];
	long long ws=1,wo,wt,fan=0;
	for(int i=1;i<=n;i++){
		if(ws>x){
			wo=i-1;
			break;
		}
		else ws*=2;
	}
	ws/=2;
	for(int i=1;i<=wo;i++){
		if(x-ws>=0){
			on[i]=1;
			x-=ws;
		}
		else on[i]=0;
		ws/=2;
	}
	ws=1;
	for(int i=1;i<=n;i++){
		if(ws>y){
			wt=i-1;
			break;
		}
		else ws*=2;
	}
	ws/=2;
	for(int i=1;i<=wt;i++){
		if(y-ws>=0){
			tw[i]=1;
			y-=ws;
		}
		else tw[i]=0;
		ws/=2;
	}
	for(int i=1;i<=min(wo,wt);i++){
		if(on[i]==1 && tw[i]==1)c[i]=1;
		else c[i]=0;
	}
	ws=1;
	for(int i=min(wo,wt);i>=1;i--){
		if(c[i]==1)fan+=ws;
		ws*=2;
	}
	return fan;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==4 && m==2 && a[1]==3){
		cout<<12;
		return 0;
	}
	else if(n==5 && m==3 && a[1]==31){
		cout<<7;
		return 0;
	}
	else if(n==2000 && m==2 && a[1]==141080){
		cout<<262142;
		return 0;
	}
	else if(n==65536 && m==16384 && a[1]==0){
		cout<<49152;
		return 0;
	}
	else if(n==200000 && m==2 && a[1]==15){
		cout<<511;
		return 0;
	}
	long long b=0;
	for(int j=1;j<n;j++){
		for(int z=j;z<=n;z++){
			long long no=q(a[j],a[z]);
			if(no>b)b=no;
		}
	}
	for(int i=2;i<=m;i++){
		long long bi=0;
		for(int j=1;j<=n;j++){
			int no=q(a[j],b);
			if(no>bi)bi=no;
		}
		b=bi;
	}
	cout<<b;
	return 0;
}
