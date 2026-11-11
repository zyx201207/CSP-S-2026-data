#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[1000010],bb=1;
bool check(long long x){
	long long s=0;
	for(int i=1;a[i]<=x;i++){
		s+=x-a[i];
	}
	return s<=m;
}
long long jisuan(long long x){
	long long s=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=x) s++;
	}
	return s;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n;i++) cin>>a[i]; 
	sort(a+1,a+n+1);
	long l=a[1],r=a[n],mid;
	while(l<=r){
		mid=l+(r-l)/2;
		if(check(mid)){
			b[bb++]=jisuan(mid);
			l=mid+1;
		}
		else r=mid-1;
	}
	long long maxx=-1;
	for(int i=1;i<=bb+1;i++){
		maxx=max(maxx,b[i]);
	}
	cout<<maxx;
	return 0;
}

