#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m;
long long a[N],s[N]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	long long ans=-1;
	long long lp=a[2]-a[1];
	bool fffff=true;
	for(int i=2;i<=n;i++)
		if(a[i]-a[i-1]!=lp){
			fffff=false;
			break;
		}
	if(fffff){
		long long ans=0,sum=0;
		for(long long i=1;i<=n;i++){
			sum+=(i-1)*lp;
			if(sum<=m)ans=i;
			else break;
		}
		cout<<ans;
		return 0;
	}
	if(n<=20000){
		for(int i=2;i<=n;i++){
			s[i]=s[i-1]+(a[i]-a[i-1])*(i-1);
			bool f=true;
			for(long long j=i;j>=1;j--)
				if(s[i]-s[j]-(a[i]-a[j])*(j-1)>m){
					ans=max(ans,i-j);
					//cout<<i<<' '<<j<<' '<<s[i]-s[j]<<" "<<ans<<'\n'; 
					f=false;
					break;
				}
			if(f)ans=i;
		}
	}else{
		for(long long i=2;i<=n;i++){
			s[i]=s[i-1]+(a[i]-a[i-1])*(i-1);
			if(s[i]<=m){
				ans=i;
				if(s[i]==m){
					while(i<n&&a[i]==a[i+1])i++,s[i]=s[i-1];
					ans=i;
				}
				continue;
			}
			int l=1,r=i-1;
			while(l<r){
				int mid=l+r>>1;
				//cout<<mid<<" ";
				if(s[i]-s[mid]-(a[i]-a[mid])*(mid-1)>m)l=mid+1;
				else r=mid;
			}
			ans=max(ans,i-l+1); 
			
		}
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
                 rp++rp++rp++rp++
rp++rp++rp++rp++ only能得分的题了rp++rp++rp++rp++ 
rp++rp++rp++rp++      求个AC     rp++rp++rp++rp++
                 rp++rp++rp++rp++
*/

