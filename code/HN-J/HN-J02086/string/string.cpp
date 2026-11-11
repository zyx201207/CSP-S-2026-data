#include<bits/stdc++.h>
using namespace std;
//Trick||Treat!
long long n,a[200005],sum[200005],s2,ans;
char c[200005];
//x=sum[n]-a+1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		if(sum[i]*2>=sum[n]){
			s2=i;
			break;
		}
	}
	long long s=0,l2=1,r2=n;
	long long lc,rc;
	while(s*2<=sum[n]&&l2<=s2&&r2>=s2){
		lc=sum[l2],rc=sum[n]-sum[r2-1];
		if(lc>rc){
			if(c[l2]!=c[r2]){
				ans+=rc-s;
			}
			r2--;
			s=rc;
		}else{
			if(c[l2]!=c[r2]){
				ans+=lc-s;
			}
			l2++;
			s=lc;
		}
	}
	ans-=(c[l2]!=c[r2])*min(lc-s,rc-s);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
