#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],vis[500005],num;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		vis[i]=vis[i-1]+a[i];
	}
	long long cnt=0;
	for(int i=1;i<=n;i++){
		if((vis[i]+m)/i==a[i+1])
		{
			cnt=i+1;
			continue;
		}
		else{
			num=max(num,cnt);
		}
	}
	cout<<num;
	return 0;
//5 8
//-3 -1 2 2 7
} 
