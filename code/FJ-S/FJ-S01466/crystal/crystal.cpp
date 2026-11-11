#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int a[500005],s[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int max=-1e8;
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int sum=m,cnt=1;
		for(int j=i-1;j>=1;j--){
			
			sum-=a[i]-a[j];
			
			cnt++;
			if(sum<=0) break;
		}
		if(cnt>=max) max=cnt;
	}
	cout<<max+1;
	//int l=1,r=1;
	//for(int i=2;i<=n;i++){
		//while(l<=i){
			//ll len=i-l;
			//ll cnt=s[i-1]+s[l-1];
			//if(len*a[i]-cnt>m){
				//l++;
			//}
		//}
	//}
	return 0;
}
