#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m;
	int n;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int j=n;j>=1;j--){
		long long sum=0,ant=0;
		for(int i=1;i<=n;i++){
			if(a[j]>=a[i]){
				sum+=a[j]-a[i];
				ant++;
			}
		}
		if(sum<=m){
			cout<<ant;
			return 0;
		}
	}
	return 0;
}
