#include<bits/stdc++.h>
using namespace std;
const int N = 5e5;
long long n,m,a[N],rm=-1e8;
bool mk(long long d){
	long long cnt,tpt;cnt=tpt=0;
	for(int i=1;i<=n;i++){
		if(a[i]<d) cnt+=d-a[i],tpt++;
	}
	if(cnt>m){
		rm=tpt;
		return false;
	}
	else return true;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;long long ms = -1e8;
	for(int i=1;i<=n;i++){
		cin>>a[i];ms=max(ms,a[i]);
	}
	long long l=0,r=ms;rm=-1e8;
	while(l<r){
		long long id=(l+r+1)>>1;
		if(mk(id))l=id;
		else r=id-1;
//		cout<<l<<' '<<r<<' '<<rm<<"\n\n"; 
	}
	cout<<rm; 
	return 0;
}

