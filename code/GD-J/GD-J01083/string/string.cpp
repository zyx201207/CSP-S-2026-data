#include<bits/stdc++.h>
using namespace std;
long long n;
long long cnt;
long long a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long aa;
	char cc;
	long long baa=0;
	char bcc='A';
	for(int i = 1;i <= n;i ++){
		cin>>aa>>cc;
		if(cc==bcc){
			baa+=aa;
			a[cnt]+=aa;
		}
		else{
			cnt++;
			a[cnt]+=aa;
			c[cnt]=cc;
			baa=aa;
			bcc=cc;
		}
	}
	long long l=0,r=cnt+1;
	long long ll=0,rr=0;
	long long ans=0;
	while(1){
		if(ll==0) {
			l++;
			ll=a[l];
		}
		if(rr==0){
			r--;
			rr=a[r];
		}
		if(l>=r) break;
		
		if(c[l]==c[r]){
			ans=ans;
		}
		else {
			ans+=min(ll,rr);
		}
		
		if(ll<rr) rr-=ll,ll=0;
		else ll-=rr,rr=0;
	}
	cout<<ans;
}










