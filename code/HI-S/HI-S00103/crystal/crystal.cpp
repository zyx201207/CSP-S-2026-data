#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int d=a[2]-a[1];
	int d1=d;
	int ans=1;
	while(m>=d1){
		m-=d1,ans++;
		if(m>=d1){
			m-=d1,ans++;
			d1+=d;
			continue;
		}
		break;
	}
	cout<<ans;
	return 0;
} 
