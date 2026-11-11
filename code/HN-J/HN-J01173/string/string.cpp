#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],l,r,ans,cnt,cnt1;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;++i) cin>>a[i]>>c[i];
	l=0,r=n-1;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]==a[r]) ++l,--r;
			else if(a[l]<a[r]) cnt=a[r]-a[l],++l;
			else cnt1=a[l]-a[r],--r;
		}else{
			if(cnt>0){
				if(a[l]<cnt) cnt-=a[l],ans+=a[l],++l;
				else if(a[l]==cnt) cnt=0,ans+=a[l],++l,--r;
				else cnt1=a[l]-cnt,ans+=cnt,cnt=0,--r;
			}else if(cnt1>0){
				if(a[r]<cnt1) cnt1-=a[r],ans+=a[r],--r;
				else if(a[r]==cnt1) cnt1=0,ans+=a[r],++l,--r;
				else cnt=a[r]-cnt1,ans+=cnt1,cnt1=0,++l;
			}else{
				if(a[l]==a[r]) ans+=a[l],++l,--r;
				else if(a[l]<a[r]) cnt=a[r]-a[l],ans+=a[l],++l;
				else cnt1=a[l]-a[r],ans+=a[r],--r;
			}
		}
	}
	cout<<ans;
	return 0;
}
