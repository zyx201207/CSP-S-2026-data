#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=500000;
int n;
ll m,a[MAXN+5];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
//	freopen("D:\\csps-new\\down\\crystal\\crystal4.in","r",stdin);
//	freopen("D:\\csps-new\\down\\crystal\\crystal.out","w",stdout);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,ans=1;
	ll sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		while(sum+m<(i-l+1)*a[i]){
			sum-=a[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
