#include<bits/stdc++.h>
using namespace std;
#define long long long long
const long long N=5e5+10;
long long arr[N];
bool rt=false;
bool tr=false;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
	long long m;
	cin>>n>>m;
	long long kt;
	long long sum=0;
	for(long long i=1;i<=n;i++){
		cin>>arr[i];
		sum+=arr[i];
		if(arr[i]-arr[i-1]!=1&&i!=1){
			rt=true;
		}
		if(i==2){
			kt=arr[2]-arr[1];
		}
		if(i>2&&arr[i]-arr[i-1]!=kt){
			tr=true;
		}
	}
	if(!rt){
		long long ans=0;
		sum/=n;
		long long l=1;
		long long r=n;
		long long mid;
		long long seat;
		while(l<=r){
			mid=(l+r)/2;
			if(arr[mid]<=sum){
				l=mid+1;
				seat=mid;
			}else{
				r=mid-1;
			}
		}
		long long tsum=m;
		if(m<=seat-1){
			ans=m+1;
		}else{
			long long i=1;
			ans=seat;
			m-=seat-1;
			while(m>0){
				ans++;
				m-=seat+i;
				i++;
			}
			ans--;
		}
		cout<<ans;
	}else if(!tr){
		long long ans=0;
		sum/=n;
		long long l=1;
		long long r=n;
		long long mid;
		long long seat;
		while(l<=r){
			mid=(l+r)/2;
			if(arr[mid]<=sum){
				l=mid+1;
				seat=mid;
			}else{
				r=mid-1;
			}
		}
		//cout<<seat<<" ";
		long long tsum=m;
		long long t=kt*(1+seat-1)*(seat-1)/2;
		//cout<<t<<" ";
		if(m<=t){
			m/=kt;
			//cout<<m<<" ";
			long long ans=1;
			long long t=1;
			while(m>0){
				m-=t;
				t++;
				ans++;
			}
			ans--;
			cout<<ans;
			//cout<<ans;
		}else{
			//cout<<"&&&&&";
			long long i=1;
			ans=seat;
			//cout<<ans;
			m-=t;
			while(m>0){
				ans++;
				m-=kt*(1+seat+i-1)*(seat+i-1)/2;
				i++;
			}
			cout<<ans;
		}
	}
	
	return 0;
}

