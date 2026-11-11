#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],d[N];
int ans,z1,z2;
int check(int z){
	int cnt=0;
	for(int i=1;i<=n;i++) {
		d[i]=abs(a[i]-a[z]);
	}
	sort(d+1,d+n+1);
	for(int i=1;i<=n;i++){
		if(m<d[i]) break;
		else {
			m-=d[i];
			cnt++;
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
	if(n%2==1){
		z1=(n+1)/2;
		cout<<check(z1);
	}
	else{
		z1=n/2;
		z2=z1+1;
		cout<<max(check(z1),check(z2));
	}
	return 0;
}
