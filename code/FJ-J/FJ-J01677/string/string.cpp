#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
//	freopen("string6.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=0,r=0,lid=1,rid=n,ans=0;
	while(lid<rid){
		while(a[lid]<=l&&lid<rid){l-=a[lid];lid++;}
		while(a[rid]<=r&&lid<rid){r-=a[rid];rid--;}
//		cout<<lid<<' '<<rid<<' '<<l<<' '<<r<<' '<<ans<<endl;
		if (a[lid]-l>a[rid]-r){
			long long s=a[rid]-r;
			if (c[lid]!=c[rid]) ans+=s;
			l+=s;r+=s;
		}else{
			long long s=a[lid]-l;
			if (c[lid]!=c[rid]) ans+=s;
			l+=s;r+=s;
		}
//		cout<<lid<<' '<<rid<<' '<<l<<' '<<r<<' '<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
