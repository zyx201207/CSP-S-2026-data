#include <bits/stdc++.h>
using namespace std;
int n,ans,ct;
long long a[500005],m,s;
int main(){
	//freopen("crystal.in","r",);
	//freopen("crystal.out","r",ct);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	sort(a+1,a+1+n);
	double cnt=s/n;
	long long minn=1e17;
	int t;
	for(int i=1;i<=n;i++){
		if(minn>abs(cnt-a[i])){
			t=i;
			minn=abs(cnt-a[i]);
		}
	}
	for(int i=1;i<=n;i++)
		if(a[i]==a[t])ct++;
	for(int i=t-1;i>=1;i--){
		if(m>=(a[t]-a[i])){
			m=m-(a[t]-a[i]);
			ans++;
		} 
		else break;
	}
	cout<<ans+ct;
	return 0;
}
