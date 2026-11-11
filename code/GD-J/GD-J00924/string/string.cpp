#include <bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=a;i<=b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
const int N=1e6+10;
struct byd{
	ll s;
	char a;
}ar[N];
ll n,m,s,ans=0;
char a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	f(i,1,n){
		cin>>ar[i].s>>ar[i].a;
	}
	ll pos=n,l=1;
	while(l<pos){
		ll sum=0;
		while(sum<ar[l].s){
			if(ar[pos].a==ar[l].a){
		    	if(ar[pos].s+sum<=ar[l].s){
	    			sum+=ar[pos].s;
	    			pos--;
		    	}else{
		    		ll op=ar[l].s-sum;
				    sum+=op;
				    ar[pos].s-=op;
	    		}
			}else{
				if(ar[pos].s+sum<=ar[l].s){
	    			sum+=ar[pos].s;
					ans+=ar[pos].s;
	    			pos--;
	    			
		    	}else{
		    		ll op=ar[l].s-sum;
//		    		cout<<op<<endl;
				    sum+=op;
				    ar[pos].s-=op;
				    ans+=op;
	    		}
			}
		}
//		cout<<l<<" "<<pos<<" "<<ans<<endl;
		l++;
	}
	cout<<ans;
	return 0;
}
