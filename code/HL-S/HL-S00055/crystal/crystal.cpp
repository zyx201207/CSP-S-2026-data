#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	if(a>b)return 1;
}
long long cnt=0;
int main(){
	freopen("crystal2.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;
	long long m;
	cin>>n>>m;
	vector<long long>a(n+5);
	for(long long i=0;i<n;i++)cin>>a[i];
	if(m==0){
		cout<<1;
		return 0;
	}
	sort(a.begin(),a.end(),cmp);
	if((a[n-2])-(a[n-1])>m){
		cout<<1;
		return 0;
	}
	for(long long i=n-1;i>=1;i--){
		if(m>=a[i-1]-a[i]&&m>=0){
			cnt++;
			m-=(a[i-1]-a[i]);
		}
	}
	cout<<cnt;
	return 0;
} 
