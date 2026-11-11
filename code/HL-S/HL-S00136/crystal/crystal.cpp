#include<bits/stdc++.h>

using namespace std;
const int N=1e5*5+10;

long long n;
long long m;
long long a[N];
long long anadd[N];
long long ans=0;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n >>m;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
	}
	if(m==0){
		cout <<1;
		return 0;
	}
	if(n==1){
		cout << 1;
		return 0;
	}
	if(n==2 && m>1){
		cout << 2;
		return 0;
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n-1;i++){
		anadd[i]=a[i+1]-a[i];
	}
	bool f=1;
	bool f1=1;
	for(int i=1;i<=n-1;i++){
		if(anadd[i]!=anadd[1]){
			f=0;
			f1=0;
		}
		if(anadd[i]!=1){
			f1=0;
		}
	}
	if(f==1){
	if(f1==1){
		if(m==2){
			cout << 2;
			return 0;
		}
		long long ans=3;long long j=1;
		for(int i=3;i<=m;i++){
			
			if(j>ans){
				ans++;
				j=1;
			}
			else{
				j++;
			}
		}
		cout << ans;
		return 0;
	}
	else{
		long long ans=3;long long j=1;
		for(long long i=3;i<=m;i++){
			
			if(j+1>ans){
				ans++;
				j=1;
			}
			else{
				j++;
			}
		}
		cout << ans;
	}
}
else{
	cout << 1;
}
	return 0;
}
