#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	if(a>b)return 1;
	else return 0;
}
long long a[200000];
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int m,n;
	cin>>n>>m;
	for(long long i=0;i<n;i++)cin>>a[i];
	if(n==1){
		cout<<a[0];
		return 0;
	}
	if(n==2){
		long long k=(a[0])&(a[1]);
		cout<<k;
		return 0;
	}
	sort(a,a+n,cmp);
	ans=a[0]&a[1];
	for(long long i=2;i<m;i+=1){
		ans=ans&a[i];
	}cout<<ans;
	return 0;
}
