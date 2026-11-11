#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,ans;
map<int,int> mp;
long long a[1145141],maxx=-1e17,minn=1e17,id;
bool tsA(){
	bool bb;
	long long xx=a[2]-a[1];
	for(int i=2;i<=min(int(n),50000000);i++){
		if(a[i]-a[i-1]!=xx){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long mm;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		for(int i=1;i<=n;i++){
			mm=m;
			for(int j=i-1;j>=1;j--){
				if(mm>=(a[i]-a[j])){
					sum++;
					mm-=(a[i]-a[j]);
				}
			}
			ans=max(ans,sum);
			sum=0;
			
		}
		cout<<ans+1;
		return 0;
	}
	else if(tsA()){
		mm=m;
		long long l=1;
		long long r=n,mid,xs;
		while(l<=r){
			mid=(l+r)/2;
			long long mx=a[n]-a[mid],sx=a[2]-a[1];
			long long xc=(mx-sx)/(a[2]-a[1])+1;
			if((sx+mx)*xc/2>mm){
				l=mid+1;
			}
			else{

				ans=max(ans,n-mid+1);
				r=mid-1;
			}
		}
		cout<<ans;
		return 0;
	}
	else{
		cout<<1;
	}
	return 0;
}

