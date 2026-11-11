#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005],mx=-1e18,k;
bool fl=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	int b=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=b){
			fl=1;
		}
	}
	if(!fl){
		int x=m/b;
		int sum=0,i;
		for(i=1;i<=n;i++){
			if(x-sum<i){
				i--;
				break;
			}
			sum+=i;
		}
		cout<<i+1;
		return 0;
	}
	sort(a+1,a+1+n);
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<' ';
//	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			long long sum=0;
			bool f=0;
			for(long long k=i;k<=j;k++){
				sum+=a[j]-a[k];
				if(sum>m){
					f=1;
					break;
				}
			}
//			cout<<i<<' '<<j<<' '<<sum<<'\n';
			if(f){
//				cout<<"Y"<<'\n';
				break;
			}
			else{
				mx=max(mx,j-i+1);
			}
		}
	}
	cout<<mx;
	return 0;
}
