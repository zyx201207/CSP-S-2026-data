#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
long long n,a[N],l=0,r=0,sum=0,ai;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i]>>c[i];
		a[i]+=a[i-1];
		r+=a[i]-a[i-1];
	} 
	int li=1,ri=n,mid=r/2,o_l=(r%2==0?0:1);
	int o_r=(r%2==0?1:0);
	int rn=r;
	a[n+1]=rn;
	while(li<ri){
		if(a[ri]-a[ri-1]>a[li]-a[li-1]) {
			r=max(a[--ri]+1,mid+o_r);
			l=(rn-r+1);
			while(a[li]<l){
				if(c[li]!=c[ri+1]) sum+=min(a[li],l)-a[li-1];
				li++;
				//cout<<sum<<"ppp\n";
			}
			if(c[li]!=c[ri+1]) sum+=min(a[li],l)-a[li-1];
			li++;//cout<<sum<<"ppp\n";
//			cout<<c[ri+1]<<"PPP\n";
			//if(c[li+1]!=c[ri]) 
		}
		else {
//			cout<<"PP1";
			l=min(a[li++],mid+o_l);
			r=(rn-l+1);//cout<<r<<"PPP\n";
			while(a[ri]>r){
				if(c[li-1]!=c[ri]) sum+=a[ri+1]-max(r,a[ri])+1;
				ri--;
//				cout<<sum<<"POP\n";
			}
			if(c[li-1]!=c[ri]) sum+=a[ri+1]-max(r,a[ri+1]);
			ri--;
		} //cout<<l<<' '<<r<<"\n";
	} cout<<sum;
	return 0;
} 
