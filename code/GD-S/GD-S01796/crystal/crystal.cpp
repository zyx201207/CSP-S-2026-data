#include <bits/stdc++.h>
using namespace std;
long long a[500010],c[500010],s,ma,li,x;
unsigned long long m;
int n;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		c[i-1]=a[i]-a[i-1];
	}
	for(int i=1;i<n;i++){
		if(c[i]==li)continue;
		s=0;
		for(int j=i;j<n;j++){
			s+=c[j]*(j-i+1);
			if(s+c[j+1]*(j-i+2)>m || j==n-1){
				x=j-i+2;
				ma=max(ma,x);
				if(j==n-1){
					cout<<ma;
					return 0;
				}
				break;
			}
		}
		li=c[i];
	}cout<<ma;
	return 0;
}
