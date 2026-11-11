#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long n,m;
	long long a[50001]={};
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long cnt=0;
	for(long long i=1;i<n;i++){
		if(a[i+1]-a[i]+cnt>=m){
			cout<<i;
			break;
		}
		cnt=cnt+(a[i+1]-a[i]);
	}
}
