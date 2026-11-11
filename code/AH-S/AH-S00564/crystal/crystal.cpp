#include<bits/stdc++.h>
using namespace std;
long long a[917813],b[917813],c[917813],maxn=LONG_LONG_MIN;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,s=0,sum=0,cnt=0,ans=0;
	cin>>n>>m;
	long long su=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	long long k=s/n;
	long long t=(s+m)/n;
	//cout<<k<<' '<<t<<endl;
	for(long long j=t;j>=k;j--){
		for(long long i=1;i<=n;i++){
			if(su+(a[i]-j)<0||(a[i]-j>0)){
				break;
			}else {
				sum++;
				if(i>maxn){
					maxn=i;
					cnt=j;
				}
			}
		}
		su=m;
	}
	//cout<<cnt;
	for(int i=1;i<=n;i++){
		if(a[i]-cnt>0){
			cout<<i-1;
			break;
		}
		//cout<<a[i]-cnt<<" "<<endl;
		ans+=(cnt-a[i]);
	}
	//cout<<ans;
	return 0;
}
//5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7
