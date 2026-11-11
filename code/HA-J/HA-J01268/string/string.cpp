#include<bits/stdc++.h>
using namespace std;
char yy,lastyaa;
bool didit=false;
long long n,sum,sum2,sum3,xx,anss,cntaa;
long long maxat,maxnn,maxn;
const int N=2e5+5;
long long a[N];
char b[N];
char caa[N*500];
map<char,long long>z;
long long ans;
long long check(){
	long long tans=0;
	for(int i=1;i<=sum/2;i++){
		if(caa[i]!=caa[sum-i+1])tans++;
	}
	return tans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cin>>xx>>yy;
	a[1]=xx;
	b[1]=yy;
	z[yy]+=xx;
	maxn=xx;
	sum+=xx;
	lastyaa=yy;
	for(int i=1;i<=xx;i++)caa[i+cntaa]=yy;
	cntaa+=xx;
	for(int i=2;i<=n;i++){
		cin>>xx>>yy;
		z[yy]+=xx;
		a[i]=xx;
		b[i]=yy;
		maxn=max(maxn,z[yy]);
		sum+=xx;
		if(lastyaa!=yy)didit=true;
		lastyaa=yy;
		for(int i=1;i<=xx;i++)caa[i+cntaa]=yy;
		cntaa+=xx;
	}
	anss=check();
	if(sum%2==0)ans=sum-maxn;
	else if(didit)ans=sum-maxn-1;
	else ans=0;
	cout<<min(anss,ans);
	return 0;
}
