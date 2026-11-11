#include<bits/stdc++.h>
using namespace std;
long long a[100086];
priority_queue<int,vector<int>,greater<int>> s;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long gc=abs(a[2]-a[1]),cnt=1;
	while(m>0){
		if(m>=gc*cnt&&ans<n){
			ans++;
		}
		m-=gc*cnt;
		cnt++;
	}
	cout<<ans+1;
	return 0;
} 
