#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,a[500000],ans=0;
char c[500000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	long long l=1,r=n,dql=a[1],dqr=a[n];
	while(l<r){
		if(dql>=dqr){ans+=dqr*(c[l]!=c[r]);dql-=dqr;dqr=0;}
		else {ans+=dql*(c[l]!=c[r]);dqr-=dql;dql=0;}
		if(dqr==0){r--;dqr=a[r];}
		if(dql==0){l++;dql=a[l];}
	}
	cout<<ans;
	return 0;
}
