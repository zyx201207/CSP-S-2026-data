#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
const int N=5e5+10;
long long a[N];
long long sum;
long long ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=1;
	for(long long r=1;r<=n;r++){
		sum+=a[r];
		while(a[r]*(r-l+1)-sum>m){
			sum-=a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
}
