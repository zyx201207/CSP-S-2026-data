#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+10;
int n;
long long m;
long long a[N];
long long ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int f=0;
	long long t=0;
	int t2=1,fl=0,cnt=0;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	    if(t+a[i]*t2>m){
	    	fl=1;
		}
		if(!fl){
			cnt=i;
			t=t+a[i]*t2;
		}
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		if((a[i]-a[i-1])!=(a[i-1]-a[i-2])){
			f=1;
			break;
		}
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			long long sum=1,last=m;
			for(int j=i-1;j>0;j--){
				if(a[i]-a[j]>last) break;
				sum++;
				last=last-(a[i]-a[j]);
			}
			ans=max(ans,sum);
		}
		cout<<ans;
		return 0;
	}
	if(!f){
		long long sum=1,last=m;
		for(int i=n-1;i>0;i++){
			if(a[n]-a[i]>last) break;
			sum++;
			last=last-(a[n]-a[i]);
		}
		cout<<sum;
		return 0;
	}
	else{
		int l=1,r=cnt;
		while(r<=n){
			long long sum=1,last=0;
			int flag=0;
			for(int i=l;i<r;i++){
				sum++;
				last=last+a[r]-a[i];
			}
			if(last<=m){
				ans=max(ans,sum);
				r++;
			}
			else l++;
		}
		cout<<ans;
	}
	return 0;
}
