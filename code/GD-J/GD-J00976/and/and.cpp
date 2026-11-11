#include<bits/stdc++.h>
using namespace std;
long long a[20000005],ans,ans1;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i =1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ans = a[1];
	for(long long i =1;i<=m;i++){
		ans = ans & a[i];
	}
	long long f = 0;
	for(long long i =1;i<=n;i++){
		long long k=1,m=0;
		while(k<a[i]){
			k*=2;
			if(a[i]==k-1){
				ans1 = a[i];
				m = 1;
				f = i;
			}
		}
		if(m==1){
			break;
		}
	}
	for(long long i =f;i<=m+f;i++){
		ans1 = ans1 & a[i];
	}
	cout<<max(ans,ans1);
}
