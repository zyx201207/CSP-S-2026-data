#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mn=5e5;const int maxn=mn+10;
int n,m,a[maxn],ans=1;
bool cmp(int a,int b){
	return a>b;
}signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=n;i++){
		if(m>=a[1]-a[i]){m-=a[1]-a[i];ans++;}
	}cout<<ans;
	return 0;
}
