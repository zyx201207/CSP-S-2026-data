#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long n,m,a[500010],num,cnt;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll l=1,r=1;
	num=1;
	while(r<n){
		r++;
		cnt+=(a[r]-a[r-1])*(r-l);
		while(cnt>m){
			cnt-=a[r]-a[l];
			l++;
		}
		num=max(num,r-l+1);
//		cout<<l<<"-"<<r<<"-"<<"so water,very easy"<<"\n";
	}
	cout<<num;
	return 0;
}

