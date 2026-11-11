#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],ll,rr,lll,rrr,t,ans,l,r,tt;
char b[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		t+=a[i];
	}
	if(t%2==1){
		l=((t>>1)),r=((t>>1)+2);
	}else{
		l=(t>>1),r=((t>>1)+1);
	}
	bool pd=0,bd=0; 
	for(int i=1;i<=n;i++){
		tt+=a[i];
		if(tt>=l&&pd==0){
			ll=i;
			lll=tt-l+1;
			pd=1;
		}if(r<=tt&&bd==0){
			rr=i;
			rrr=r-tt+a[i];
			bd=1;
		}if(pd==1&&bd==1)break;
	}
	while(ll>0){
		if(a[ll]-lll+1>a[rr]-rrr+1){
			if(b[ll]!=b[rr]){
				int bb=a[rr]-rrr+1;
				ans+=bb;
				l-=bb;
				lll+=bb;
				r+=bb;
				rr++;
				rrr=1;
			}else if(b[ll]==b[rr]){
				int bb=a[rr]-rrr+1;
				l-=bb;
				lll+=bb;
				r+=bb;
				rr++;
				rrr=1;
			}
		}else if(a[ll]-lll+1<a[rr]-rrr+1){
			
			if(b[ll]!=b[rr]){
				int bb=a[ll]-lll+1;
				ans+=bb;
				r+=bb;
				rrr+=bb;
				l-=bb;
				ll--;
				lll=1;
			}else if(b[ll]==b[rr]){
				int bb=a[ll]-lll+1;
				r+=bb;
				rrr+=bb;
				l-=bb;
				ll--;
				lll=1;
			}
		}else{
			if(b[ll]!=b[rr]){
				int bb=a[ll]-lll+1;
				ans+=bb;
				r+=bb;
				rr++;
				rrr=1;
				l-=bb;
				ll--;
				lll=1;
			}else if(b[ll]==b[rr]){
				int bb=a[ll]-lll+1;
				r+=bb;
				rr++;
				rrr=1;
				l-=bb;
				ll--;
				lll=1;
			}
		}
	}cout<<ans;
}
