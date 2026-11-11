#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200005],l1=0;
string s,s1,x,y;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);  
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	scanf("%lld",&a[i]);
    	cin>>s1;
    	s+=s1;
    	l1+=a[i];
	}
	long long ans=0,l=l1/2,pi=0,qi=a[1],r=1,qj=l1,pj=l1-a[n];
	for(long long i=1;i<=l;i++){
		long long j=l-i+1;
		if(pi<i&&i<=qi){
		    x=s[r-1];
		}
		else{
			pi=qi;
			r++;
			qi+=a[r];
			x=s[r];
		}
		if(pj<j&&i<=qj){
			y=s[n];
		}
		else{
			qj=pj;
			n--;
			pj-=a[n];
			y=s[n];
		}
		if(x!=y){
		    ans++;
		}
	}

	printf("%lld",ans);
    return 0;
}
