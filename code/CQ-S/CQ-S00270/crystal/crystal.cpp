#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long a[N],n,m,x,y=INT_MAX,z,p,q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	while(m){
		q=0;y=INT_MAX;z=0;p=0;
		for(int i=n;i>0;--i){
			z=y;
			if(a[i]-a[i-1]>0)y=min(a[i]-a[i-1],y);
			else ++q;
			if(y!=z)p=i;
		}
		if(m-(a[p]-a[p-1])*x>0){
			m-=(a[p]-a[p-1])*x;
			++x;
		}else{
			break;
		}
	}
	cout<<x;
	return 0;
}
