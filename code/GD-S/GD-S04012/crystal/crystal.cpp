#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005],m;
int n,mx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	
	int i=n;
	for(;i>1;i--){
		int cnt=1,num=m;
		for(int j=i-1;j>0;j--) if(num>=a[i]-a[j]) num-=a[i]-a[j],cnt++;
		mx=max(mx,cnt);
	}
	cout<<mx;
	return 0;
}
