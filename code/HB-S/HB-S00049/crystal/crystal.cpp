#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],max1=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
	}
	for(long long i=n;i>max1;i--){
		long long bb=a[i],id=i-1;
		for(long long j=1;j<=id;j++){
			long long sum1=b[id]-b[j-1],sum2=(id-j+1)*bb;
			if(sum2-sum1<=m){
				max1=max(max1,i-j+1);
				break;
			}
		}
	}
	cout<<max1;
	return 0;
}
