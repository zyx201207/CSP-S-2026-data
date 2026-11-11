#include<bits/stdc++.h>
using namespace std;
long long n,l=1,r,m,l2=1,r2,ans,a[200020],b[200020],d[2000020],aum;
char c[200020];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r2=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[i]=b[i-1]+a[i];
	}
	r=b[n];
	for(int i=1;i<=n;i++){
		if(r/2>=b[i] && r/2<=b[i]){
			m=i;
			break;
		}
	}
	for(int i=n;i>=0;i--){
		d[i]=d[i+1]+a[i];
	}
	while(l<r){
		if(c[l2]!=c[r2]){
			if(a[l2]<=a[r2]){
				aum=b[l2]-l+1;
				l+=aum;
				r-=aum;
				ans+=aum;
				l2++;
			}
			if(a[l2]>a[r2]){
				aum=d[r2]-(b[n]-r);
				r-=aum;
				l+=aum;
				ans+=aum;
				r2--;
			}
		}
		else{
			if(a[l2]<=a[r2]){
				aum=b[l2]-l+1;
				l+=aum;
				r-=aum;
				l2++;
			}
			if(a[l2]>a[r2]){
				aum=b[r2]-(b[n]-r);
				r-=aum;
				l+=aum;
				r2--;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
