#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],maxx=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if((a[i]-a[i-1])*(i-1)<=m){
			m-=(a[i]-a[i-1])*(i-1);
			maxx++;
		}else{
			break;
		}
	}
	cout<<maxx;
	return 0;
} 
