#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005],b[500004];
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("crystal4.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
//	for(int i=1;i<=n;i++){
//		printf("a:%lld\n",a[i]);
//	}
	for(int i=1;i<=n-1;i++){
		b[i]=a[i+1]-a[i];
//		if(b[i]!=0){
//		printf("b:%lld i:%d\n",b[i],i);
//		}
	}
	if(m>=1000000000000000000){
		long long k=1,s=0;
		int cnt=1;
		for(int j=i;j<=n-1;j++){
			s+=b[j]*cnt;
			if(s>=m)break;
			cnt++;
			k++;
		}
		cout<<k;
		return 0;
	}
	long long max_k=0;
	for(int i=1;i<=n;i++){
		long long k=1,s=0;
		int cnt=1;
		for(int j=i;j<=n-1;j++){
			s+=b[j]*cnt;
//			printf("cnt:%d\n",cnt);
//			printf("s:%lld\n",s);
			if(s>=m)break;
			cnt++;
			k++;
		}
		max_k=max(max_k,k);
		if(n-i<=max_k)break;
	}
	cout<<max_k;
	return 0;
} 
//Oct31==Dec25?
