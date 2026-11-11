#include<bits/stdc++.h>
using namespace std;
const int maxn=500000+10;
long long n,m,ma=0;
long long a[maxn];
long long r(long long x){
	long long l=x,r=n,cnt=0,mo=m;
	for(int j=1;j<=x;j++){
		if(a[j]<=a[x] && (a[x]-a[j])<=mo){
			if(a[j]==a[x]){
				cnt++;
				continue;
			}
			if(mo>0){
				while(mo!=0 && a[j]<a[x]){
					a[j]++;
					mo--;
				}
				if(a[j]==a[x]){
					cnt++;
				}
			}
			else break;
		}
	}
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ma=max(ma,r(i));
	}
	cout<<ma;
	return 0;
}
