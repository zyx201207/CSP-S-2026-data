#include<bits/stdc++.h>
using namespace std;
long long a1[200005],a[200005];char b1[200005],b[200005];long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>b[i];ans+=a[i];
	}
	long long x=a[1],y=a[n];char q=b[1],p=b[n];
	long long an=0;
	if(p!=q){
		long long z=min(x,y);x-=z;y-=z;an+=z;
	}
	if(q==p){
		long long z=min(x,y);x-=z;y-=z;
	}
	int l=1,r=n;long long ll=a[1],rr=a[n];
	while(l<r){
		if(x==0&&y==0){
			if((l+2)==r)break;
		}
		if(x==0){
			l++;ll+=a[l];
			x=a[l];q=b[l];
			if(ll>(ans/2)){
				if(ans%2==0){
					x=(ans/2)-(ll-(ans/2));
				}
				else {
					x=((ans+1)/2)-(ll-(ans+1)/2)-1;
				}
			}				
		}
		if(y==0){
			r--;rr+=a[r];y=a[r];p=b[r];
			if(rr>(ans/2)){
				if(ans%2==0){
					y=(ans/2)-(rr-(ans/2));
				}
				else {
					y=((ans+1)/2)-(rr-(ans+1)/2)-1;
				}
			}
		}
		if(p!=q){
			long long z=min(x,y);x-=z;y-=z;an+=z;
		}
		if(q==p){
			long long z=min(x,y);x-=z;y-=z;
		}
		if((l+1)==r)break; 
	}
	cout<<an;return 0;
}
