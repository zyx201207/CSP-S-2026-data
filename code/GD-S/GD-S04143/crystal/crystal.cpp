#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	long long cnt=0;
	long long a[1000000000005];
	for(long long i=1;i<=n;i++){
		cin>>a[i];		
	}
	
	for(int i=n;i>0;i--){
		while(m>0){
			m-=(n-a[i]);
			cnt++;		
		}
	}
	cout<<cnt;
	return 0;
}
