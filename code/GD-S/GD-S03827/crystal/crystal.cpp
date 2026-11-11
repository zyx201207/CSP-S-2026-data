#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
long long a[500010];

bool check(int mi){
	long long s=0;
	for(int i=1;i<=mi-1;++i){
		s+=a[i];
	}
	for(int i=mi;i<=n;++i){
		s+=a[i];
		if(1ll*a[i]*mi-s<=m)return 1;
		s-=a[i-mi+1];
	}
	return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n+1;
	while(l+1<r){
		int mi=(l+r)/2;
		if(check(mi))l=mi;
		else r=mi;
	}
	cout<<l;
	return 0;
} 
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
