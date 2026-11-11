#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	long long s=0;
	for(int t=31;t>=0;t--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if((a[i]&s)==s&&(a[i]&(1ll<<t))>0)cnt++;
		}
		if(cnt>=m)s+=(1ll<<t);
	}
	cout<<s;
	return 0;
}
