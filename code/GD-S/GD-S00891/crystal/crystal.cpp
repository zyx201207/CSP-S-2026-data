#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long b[500005];
long long ans=-999999999;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool pan=0,ppan=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) pan=1;
		if(a[i]-a[i-1]!=a[2]-a[1]) ppan=1;
	}
	if(pan==1 and ppan==1){
		long long s=0; 
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			b[i]=a[1]-a[i];
		}
		for(int i=1;i<=n;i++){
			if(i!=1){
				s+=a[i]-a[i-1];
			}
			long long cnt=m;
			long long anss=1;
			long long ss=i-1;
			while(ss>0 and cnt>=b[ss]+s){
				anss++;
				cnt-=(b[ss]+s);
				ss--;
			}
//			cout<<s<<endl;
			ans=max(ans,anss);
		}
		cout<<ans;
	}else if(pan==1){
		long long sss=0;
		long long ssss=0;
		while(ssss<=m){
			sss++;
			ssss+=sss;
		}
		cout<<sss-1;
	}else{
		long long sss=0;
		long long ssss=0;
		while(ssss<=m){
			sss++;
			ssss+=sss*(a[2]-a[1]);
		}
		cout<<sss-1;
	}
	
 
	
}
