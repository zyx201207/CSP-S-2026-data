#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200010];
pair<long long,long long>d[200010];
char c[200010];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long l=1,r=n,ll=1,rr=0,sum;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		d[i]={d[i-1].second+1,d[i-1].second+a[i]};
		rr+=a[i];
	}
	sum=rr;
	long long ans=0;
	for(;l<=r;){
		long long lenl,lenr;
		lenl=d[l+1].first-ll;
		lenr=rr-d[r-1].second;
		if(c[l]!=c[r]){
			long long len=min(lenl,lenr);
			ans+=len;
		}
		if(lenl<lenr){
			l++;
			ll+=lenl;
			rr-=lenl;
		}else if(lenl>lenr){
			r--;
			ll+=lenr;
			rr-=lenr;
		}else{
			l++;
			r--;
			ll+=lenl;
			rr-=lenl;
		}
	}
	cout<<ans<<'\n';
}
  
