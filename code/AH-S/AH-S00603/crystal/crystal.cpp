#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],x[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1){
			x[i]=a[i]-a[i-1];
		}
	}
	sort(a+1,a+n+1);
	int i=n,j=n;
	long long sum=0;
	int cnt=0;
	while(i>=1){
		if(sum>m){
			sum-=(j-i)*x[j];
			sum+=a[j-1]-a[i-1];
			i--;
			j--;
		}else{
			cnt=max(cnt,j-i+1);
			i--;
			sum+=a[j]-a[i];
		}
	}
	cout<<cnt<<endl;
	return 0;
}
