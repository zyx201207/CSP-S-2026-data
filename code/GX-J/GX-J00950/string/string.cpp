#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);cout.tie(0);
	int n,sum=0;cin>>n;
	if(n==1){cout<<0;return 0;}
	int a[n+1]={0};
	char b[n+1];
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>b[i];
	}
	int s=0;
	for(int i = 1;i <= n;i++){
		if(!a[i] || !a[i+1])break;
		if(s >= n)break;
		while(a[i]){
			if(!a[n-s] || !a[i])break;
			if(b[i] != b[n-s])sum+=max(min(a[n-s],a[i]),(int)0);
			int zj=a[i];
			a[i]-=a[n-s];
			a[i]=max(a[i],(int)0);
			a[n-s]-=zj;
			a[n-s]=max(a[n-s],(int)0);
			if(!a[n-s])s++;
			else continue;
		}
	}
	cout<<sum;
}
