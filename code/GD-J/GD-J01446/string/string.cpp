#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
char s[200005];
int n,len=0;
signed main(){
	ios::sync_with_stdio(false),
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
		len+=a[i];
	}
	int hlf=len/2;
	cout<<hlf<<'\n';
	int li=0,ri=n-1;
	char lc=s[0],rc=s[n-1];
	int l=a[0],r=a[n-1],ans=0;
	if(l==r && lc==rc)ans=a[0];
	else if(lc!=rc)ans=0;
	else if(l>r)ans=l-r,ri--;
	else ans=r-l,li++;
	while(l<=hlf || r<=hlf){
		lc=s[li],rc=s[ri];
		if(l<r){
			if(lc==rc){
				ans+=r-l;
			}
			l+=a[li++];
		}else if(l>r){
			if(lc==rc){
				ans+=l-r;
			}
			r+=a[ri--];
		}else{
			l+=a[li++];
			r+=a[ri--];
			if(l==r && lc==rc)ans+=min(a[li-1],a[ri-1]);
		}
	}
	cout<<hlf-ans;	
	return 0;
}
