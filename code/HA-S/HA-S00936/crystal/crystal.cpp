#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],q[500010],ma=0,l=1;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>a[i];
sort(a+1,a+n+1);
for(int i=2;i<=n;i++){
	q[i]=q[i-1]+((a[i]-a[i-1])*(i-1));
}
for(int i=2;i<=n;i++){
	if(q[i]-q[l]-((a[i]-a[l])*(l-1))>m){
		while(q[i]-q[l]-((a[i]-a[l])*(l-1))>m){
			l++;
			if(q[i]-q[l]-((a[i]-a[l])*(l-1))<=m)break;
		}
	}
	if(i-l+1>ma)ma=i-l+1;
}
cout<<ma;
return 0;
}
