#include<bits/stdc++.h>
using namespace std;
long long s[500005],a[500005];
long long n,m,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long l=1,r=1;
	while(r<=n){
//		cout<<l<<' '<<r<<' '<<a[r]*(r-l+1)-s[r]+s[l-1]<<endl;
		if(a[r]*(r-l+1)-s[r]+s[l-1]<=m)
		ans=max(ans,r-l+1);
		if(l==r){
			r++;
		}
		else if((a[r]*(r-l+1)-s[r]+s[l-1])>=m){
//			cout<<1333;
			l++;
		}
		else{
			r++;
		}
	}
	cout<<ans;
}
