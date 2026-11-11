#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,l,p,minx=10000000000005,ans,A,B,A1,maxx;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long m1=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		if(i==1) continue;
        if(i==2) A1=a[i]-a[i-1];
        else if(a[i]-a[i-1]!=A1){
        	A=1;
		}
	}
	if(A==0){
		long long y=0;
		while(m1>0&&ans<n-1){
			y+=A1;
			if(m1>=y){
				ans++;
				m1-=y;
			}
			else m1=0;
		}
		cout<<ans+1;
		return 0;
	}
	l=sum/n;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		long long t=a[i]-l;
		if(t<0) t=0-t;
		if(t<=minx){
			minx=t;
			p=i;
		}
	}
	if(n<=5000){
		for(int i=2;i<=n;i++){
			m1=m;
			for(int j=i;j>=1;j--){
				if(m1>=(a[i]-a[j]))
				{
		           m1-=(a[i]-a[j]);
		           ans++;
		        }
		        else break;
			}
			if(ans>maxx) {
				maxx=ans;
			}
			ans=0;
		}
		cout<<maxx;
		return 0;
	}
	for(int i=p;i<=p+1000&&i<=n;i++){
		m1=m;
    for(int j=i;j>=1;j--){
		if(m1>=(a[p]-a[j]))
		{
		    m1-=(a[p]-a[j]);
		    ans++;
		}
		    else break;
	}
		if(ans>maxx) {
			maxx=ans;
		}
		ans=0;
    }
    for(int i=p;i>=p-1000&&i>=1;i--){
		m1=m;
    for(int j=i;j>=1;j--){
		if(m1>=(a[p]-a[j]))
		{
		    m1-=(a[p]-a[j]);
		    ans++;
		}
		    else break;
	}
		if(ans>maxx) {
			maxx=ans;
		}
		ans=0;
    }
	cout<<maxx;
	return 0;
}
