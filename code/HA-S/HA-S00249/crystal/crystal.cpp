#include<bits/stdc++.h>
using namespace std;
long long max1=-1000,n,a[100086],m,s=0,h=0,g[1000086],f=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++)cin>>a[i];
	for(long long j=0;j<n;j++){
		for(long long i=j;i<n;i++){
			s=s+a[i];
			h=(s+m)/(i-j+1);
			if(h==a[i]){
				f++;
				max1=max(max1,i-j+1);
				if(i-j+1==n){
					cout<<n;
					return 0;
				}
			}
		}
		s=0;
	}
	cout<<max1;
	return 0;
}
