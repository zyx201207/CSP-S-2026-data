#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],ans;
char b[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int l=1,r=n,la=a[1],ra=a[n];
	while(l<r){
		if(b[l]==b[r]){
			if(la>ra){
				la-=ra;
				r--;
				ra=a[r];
			}else if(ra>la){
				ra-=la;
				l++;
				la=a[l];
			}else{
				la=0,ra=0;
				l++,r--;
				la=a[l],ra=a[r];
			}
		}else{
			if(la>ra){
				la-=ra;
				ans+=ra;
				r--;
				ra=a[r];
			}else if(ra>la){
				ra-=la;
				ans+=la;
				l++;
				la=a[l];
			}else{
				ans+=la;
				la=0,ra=0;
				l++,r--;
				la=a[l],ra=a[r];
			}
		}
	}
	cout<<ans;
	return 0;
}
