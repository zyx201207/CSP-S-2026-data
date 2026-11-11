#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll sum=0,cnt=0;
	for(int i=1;i<=m;i++){
		sum=a[n]-a[i];
		if(sum<=m){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
