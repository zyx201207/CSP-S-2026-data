#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long sum,_1,ans;
int main(){//25~65
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	bool _2=1;
	for(int i=1;i<=n-2;i++){
		if(!(a[i]-a[i+1]==a[i+1]-a[i+2])){
			_2=0;
		}
	}
	if(_2){
		int alpha=a[2]-a[1];
		if(alpha==0){
			cout<<n;return 0;
		}else{
			m=m/alpha;
			cout<<(1+(long long)sqrt(1+8*m))/2;
		}
	}else{
	for(int i=1;i<=n;i++){
		sum=0;_1=1;
		for(int j=i-1;j>=1;j--){
			sum+=a[i]-a[j];
			if(sum>m)break;
			else _1++;
		}
		ans=max(ans,_1);
	}
	cout<<ans;
}
	return 0;
}
