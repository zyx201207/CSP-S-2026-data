#include<bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;
ll m,a[N],l=1,r,ma=1,s,n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	r++;
	for(int i=2;i<=n;i++){
		s+=(a[i]-a[i-1])*(r-l+1);
		while(r>=l&&s>m){
			s-=a[i]-a[l];
			l++;
		}
		a[++r]=a[i];
		ma=max(r-l+1,ma);
	}
	cout<<ma;
	return 0;
}/*
пепепепепе 
*/
