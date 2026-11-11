#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=5e5+10;
int n;
long long m,a[N],sum,cnt;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
	sort(a+1,a+n+1); 
	long long yha=0;
	for(int i=1;i<n;i++) yha+=a[n]-a[i];
	if(yha<=m){
		cout<<n;
		return 0;
	}
	sum/=n;
	for(int i=1;i<=n;i++) a[i]-=sum;
	sort(a+1,a+n+1);
	int z=0;
	for(int i=1;i<=n;i++){
		if(!a[i]) cnt++;
		else if(a[i]<0&&m+a[i]>=0) m+=a[i],cnt++;
		else if(a[i]>0){
			z=i;	
			break;
		}
	}
	long long fz=0;
	while(m-cnt>=0){
		m-=cnt;
		fz++;
		while(a[z++]==fz&&z<=n) cnt++;
		if(z>n) z=1;
	}
	cout<<cnt;
	return 0;
} 
/*
5 8
-3 -1 2 2 7

5 5
1 2 4 8 9
*/ 
