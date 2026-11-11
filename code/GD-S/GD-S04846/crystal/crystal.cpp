#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m,b[500005],ma;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	long long l=1,r=1;
	while(r<=n){
		long long cnt=a[r]*(r-l+1)-b[r]+b[l-1];
		if(cnt>m){
			l++;
		}
		else{
			ma=max(ma,r-l+1);
			r++;
		}
	}
	cout<<ma;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
