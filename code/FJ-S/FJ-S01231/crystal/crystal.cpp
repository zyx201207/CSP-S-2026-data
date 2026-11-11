#include<bits/stdc++.h>
using namespace std;
long long n,m,a[555555],s,l=1,x; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int r=1;r<=n;r++){
		x+=(r-l)*(a[r]-a[r-1]);
		while(x>m){
			x-=(a[r]-a[l]);
			l++;
		}
		s=max(s,r-l+1);
	}
	cout<<s;
	return 0;
}
