#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a[100005],b[100005];
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=1;
	cin>>n>>m;
	for(long long i=0;i<n;i++)cin>>a[i];
	sort(a+0,a+n);
	long long mid=n/2+1;
	for(long long i=0;i<n;i++){
		b[i]=abs(a[i]-a[mid]);
	}
	sort(b,b+n);
	long long m1=0;
	for(long long i=1;i<n;i++){
		if(m1+b[i]<=m){
			ans++;
			m1+=b[i];
		}else{
			break;
		}
	}
	cout<<ans;
	return 0;
}
