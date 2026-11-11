#include<bits/stdc++.h>
using namespace std;
long long a[214514];
char c[214514];
long long b[214514];
char cc[214514];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long sum=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	long long l=1,r=n,cnt=0,cntt=0;
	long long ans=0;
	while(l<r){
		cnt+=a[l];
		cntt+=a[r];
		if(cnt<=cntt){
			if(c[l]!=c[r]){
				ans+=min(a[l],a[r]);
			}
			l++;
			a[r]=cntt-cnt;
			cntt-=a[r];
		}
		else{
			if(c[l]!=c[r]){
				ans+=min(a[l],a[r]);
			}
			r--;
			a[l]=cnt-cntt;
			cnt-=a[l];
		}
	} 
	cout<<ans; 
} 
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
