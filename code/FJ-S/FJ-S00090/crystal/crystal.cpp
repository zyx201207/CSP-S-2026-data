#include <bits/stdc++.h>
using namespace std;
const long long MAXX=1e13+2;
int n;
long long m;
long long a[500005];
int ans=0;
int check(long long x){
	int cnt=0;
	long long sum=0;
	int flag;
	for(int i=n;i>=1;--i){
		if(a[i] <= x){
			flag=i;
			break;
		}
	}
	for(int i=flag;i>=1;--i){
	    sum=sum+x-a[i];
		if(sum <= m) cnt++;
		else break;
	}
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long l=MAXX,r=-MAXX;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		l=min(l,a[i]);
		r=max(r,a[i]);
	}
	sort(a+1,a+1+n);
    for(int i=l;i<=r;++i){
    	ans=max(ans,check(i));
	}
	cout<<ans;
	return 0;
}
