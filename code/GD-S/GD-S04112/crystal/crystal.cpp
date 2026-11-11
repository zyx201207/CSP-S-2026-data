#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],s[500001],sun=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]-a[i-1]>0)s[i]=s[i-1]+(a[i]-a[i-1])*(i-1);
		else s[i]=s[i-1]+(a[i-1]-a[i])*(i-1);
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if((s[j]-s[i])/i<=m)
			if(sun<j-i+1)sun=j-i+1;
		}
	}
	cout<<sun;
}
