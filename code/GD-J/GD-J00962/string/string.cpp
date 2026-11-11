#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N],b[N];
char c[N],s[N];
signed main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[n-i+1]=a[i];
		s[n-i+1]=c[i];
	}
	int la=0,lc,ra=0,rc;
	for(int i=1;i<=(n+1)/2;i++){
		if(la>0){
			if(lc!=s[i]){
				ans+=la;
				b[i]-=la;
				la=0;
			}
		}
		if(ra>0){
			if(rc!=c[i]){
				ans+=ra;
				a[i]-=ra;
				ra=0;
			}
		}
		if(c[i]!=s[i]){
			ans+=min(a[i],b[i]);
		}
		if(a[i]>b[i]){
			la+=a[i]-b[i];
			lc=c[i]; 
		}else {
			ra+=b[i]-a[i];
			rc=s[i];
		}
	}
	cout<<ans;
	return 0;
} 
