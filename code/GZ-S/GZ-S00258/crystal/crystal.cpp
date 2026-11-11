//GZ-S00258 ³Â±òˆ 
#include<bits/stdc++.h>
using namespace std;
const int N=5000000+10;
int a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int mid=(1+n)>>1;
	long long ans=0;
	for(int i=n;i>=1;i--){
		long long cnt=0;
		int x=m;
		for(int j=i;j>=1;j--){
			if(x>=a[i]-a[j]){
				cnt++;
				x-=a[i]-a[j];
			}else{
				break;
			}
		}
		if(cnt>ans){
			ans=cnt;
		}
	}
	cout<<ans;
	return 0;
} 
