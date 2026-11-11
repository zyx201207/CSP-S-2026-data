#include<bits/stdc++.h>
using namespace std;
long long a[500005],qz[500005];
long long n,m;
bool cmp(int x,int y){
	return x<y;
}

bool check(int cnt){
	long long sum=0,minn=LONG_LONG_MAX;
	for(int i=cnt;i<=n;i++){
		sum=a[i]*cnt-(qz[i]-qz[i-cnt]);
		minn=min(minn,sum);
	}
	return minn<=m;
}

long long ef(long long l,long long r){
	while(l<r){
		long long mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
		} 
		else r=mid-1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qz[i]=a[i]+qz[i-1];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		qz[i]=a[i]+qz[i-1];
	}
	long long cnt=ef(1,n);
	cout<<cnt;
	return 0;
}
