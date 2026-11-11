#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,i,a[N],s,l,ma;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	l=ma=1;
	for(i=2;i<=n;i++){
		s+=(a[i]-a[i-1])*(i-l);
		while(s>m){
			s-=(a[i]-a[l]);
			l++;
		}
		ma=max(ma,i-l+1);
	}
	cout<<ma;
}
