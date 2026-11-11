#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,ans;
ll m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ll sum=0;int pos=1;
	for(int i=1;i<=n;i++){
		if(i>1)sum+=(a[i]-a[i-1])*(i-pos);
		while(sum>m){
			sum-=a[i]-a[pos];
			pos++;
		}
		ans=max(ans,i-pos+1);
	}
	cout<<ans;
	return 0;
}
