//GZ-S00124   遵义市朝阳小学   何致远 
#include <bits/stdc++.h>
using namespace std;
//struct 
 long long a[500005],s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    long long n,o=0,f=1;
    unsigned long long m;
	cin>>n>>m;
	cin>>a[1];
	for(long long i=2;i<=n;i++){
		cin>>a[i];
		if(i==2){
			o=a[2]-a[1];
		}
		if(a[i]-a[i-1]!=o){
			f=0;
		}
	} 
	if(f==1){
	    m/=o;
	    for(long long i=1;i<=m;i++){
	    	if(i*(i+1)<=m*2&&(i+2)*(i+1)>m*2){
	    		cout<<i+1;
	    		return 0;
			}
		}
	}
	sort(a+1,a+n+1);
	
	long long ss=0,mx=0,mmx=0,mxx=1,e=0,p;
	for(long long i=2;i<=n;i++){
		    p=i-1;
		    s[i]=s[i-1]+a[i]-a[i-1];
		    ss+=(a[i]-a[i-1])*p;
		    ++mxx;
		    if(s[i]>mx){
		    	mx=s[i];
				e=i-1;
			}
		    if(ss>m){
		    	ss-=mx;
		    	mx=s[e];
		    	e--;
		    	p--;
		    	mxx--;
			}
			p++;
	} 
	cout<<mxx;
	return 0;
}

