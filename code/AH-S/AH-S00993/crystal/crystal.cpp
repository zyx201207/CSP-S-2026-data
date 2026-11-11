#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m,p,c=1,t,d,s,ans,i,a[N];
bool deng(){
	if(n<=1)return 1;
	d=a[2]-a[1];
	for(i=2;i<n;i++){
		if(a[i+1]-a[i]!=d)return 0;
	}
	return 1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(deng()){
		if(n==1){
			cout<<0;
			return 0;
		}
		s=0,t=m;
		for(i=1;i<=n;i++){
			s+=d;
			if(t>=s)t-=s,ans++;
			else break;
		}
		cout<<ans;
		return 0;
	}
	for(i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			continue;}
		p=i-1,t=m,s=1;
		while(p>=1){
			t-=a[i]-a[p];
			if(t>=0)s++,p--;
			else break;
		}
		ans=max(ans,s);
	}
	cout<<ans;
	return 0;
}
