#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long m,a[N];
int n,s;
int main(){
	freopen("crystal.in" ,"r",stdin );
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int l=1;
	long long x;
	for(int r=1;r<=n;r++){
		x+=a[r];
		long long ad=(r-l+1)*a[r]-x;
		while(ad>m){
			x-=a[l];
			l++;
			ad=(r-l+1)*a[r]-x;
		}
		s=max(s,(r-l+1));
	}
	cout<<s;
	return 0;
}
