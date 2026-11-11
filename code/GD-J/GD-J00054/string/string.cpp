#include <bits/stdc++.h>
using namespace std;
long long n,a[200000+10],sum=0,z,l=0,r=0,cnt=0,ll,rr;
string s;
char c[200000+10];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	z=sum/2;
	long long d=1;
	long long x=1;
	r+=a[n];
	for(long long i=1;i<=n;i++){
		l+=a[i];
		if(l>z){
			l=z;
		}
		x=1;
	    while(true){
	    	if(x==1){
	    		cnt+=rr;
	    		d++;
	    		x++;
	    		continue;
			}
	    	if(r>=l){
	    		if(c[i]!=c[n-d+1]){
			        cnt+=a[n-d+1];
	    			cnt-=(r-l);
				}
				rr=r-l;
				break;
			}else{
				if(c[i]!=c[n-d+1]){
					cnt+=a[n-d+1];
				}
				d++;
				r+=a[n-d+1];
				x++;
			}
		}
		if(l>=z){
			break;
		}
	}
	cout<<cnt;
	return 0;
}
