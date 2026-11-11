#include<bits/stdc++.h>
using namespace std;
const int MAXX=500005;
long long n,m,a[MAXX],s,b[MAXX];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1)s+=abs(a[i]-a[i-1]);
	}
	if(m>=s){
		cout<<n;
		return 0;
	}
	sort(a+1,a+1+n);
	int l=1,r=1,ma=1,c=m;
	while(r<=n){
		if(c>=(a[r+1]-a[r])*(r-l+1)){
			c-=(a[r+1]-a[r])*(r-l+1);
			r++;
			ma=max(ma,r-l+1);
		}
		else{
			c+=(a[r]-a[l]);
			l++;
		}
	}
	cout<<ma;
	return 0;
}
