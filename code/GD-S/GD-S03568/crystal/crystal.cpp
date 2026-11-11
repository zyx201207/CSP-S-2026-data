#include<bits/stdc++.h>
using namespace std;
const long long N=5000005;
long long sum,cnt,l,n,m,ans,a[N],s[N],b[N];
void op(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}
int main(){
	op();
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
		s[i]=s[i-1]+b[i];
	}
	sum=0,cnt=0,l=1;
	for(long long i=1;i<=n;i++){
		cnt++;
		ans=max(ans,cnt);
		sum+=(cnt*b[i]);
		if(sum>m){
			sum-=s[i]-s[l-1];
			l++;
			cnt--;
		}
	}
	cout<<ans;
}
