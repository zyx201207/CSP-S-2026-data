#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
long long n;
long long a[N];
char c[N];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n,le=0,rt=0;
	char lnow,rnow;
	while(l<=r){
		if(le==0&&rt==0){
			le=le+a[l];
			lnow=c[l];
			l++;
		}
		else if(le>=rt){
			rt=rt+a[r];
			rnow=c[r];
			r--;
			if(rt>=le){
				rt=rt-le;
				if(lnow!=rnow){
					ans=ans+le;
				}
				le=0;
			}
			else if(rt<le){
				le=le-rt;
				if(lnow!=rnow){
					ans=ans+rt;
				}
				rt=0;
			}
		}
		else if(le<rt){
			le=le+a[l];
			lnow=c[l];
			l++;
			if(rt>=le){
				rt=rt-le;
				if(lnow!=rnow){
					ans=ans+le;
				}
				le=0;
			}
			else if(rt<le){
				le=le-rt;
				if(lnow!=rnow){
					ans=ans+rt;
				}
				rt=0;
			}
		}
		//cout<<l<<' '<<r<<' '<<le<<' '<<rt<<' '<<lnow<<' '<<rnow<<endl;
	}
	cout<<ans;
	return 0;
}
