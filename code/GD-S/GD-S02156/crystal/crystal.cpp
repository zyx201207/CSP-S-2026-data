#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int maxn=5e5+10;
long long n,m,sum,summ,ans;
long long a[maxn];
long long f(long long x){
	for(int i=1;i<=x;i++){
		summ+=abs(a[x]-a[i]);
	}
	return summ;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum+=abs(a[n]-a[i]);
	}
	if(m>=sum){
		cout<<n;
		return 0;
	}
	long long p=0,t1=0,mi=LLONG_MAX;
	for(int i=1;i<=n;i++){
		t1=abs(m-f(i));
		if(t1<=mi){
			mi=t1;
			p=a[i];
		}
	}
	//cout<<p<<endl;
	for(int i=1;i<=n;i++){
		if(a[i]==p){
			ans++;
		}else{
			if(m<=0){
				cout<<ans;
				return 0;
			}else{
				long long res=m;
				if(res-abs(p-a[i])>=0&&p>a[i]){
					m-=abs(p-a[i]);
					ans++;
					//cout<<a[i]<<" "<<m<<" "<<abs(a[i]-p)<<" "<<ans<<endl;
				}
			}
		}
		if(m>0&&i==n){
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
