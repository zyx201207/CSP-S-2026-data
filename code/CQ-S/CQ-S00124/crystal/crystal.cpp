#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N],s[N],ss[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int d=a[2]-a[1];
	a[0]=a[1]-d;
	int fl=0;
	for(int i=1;i<=n;i++){
		if(!fl&&a[i]-a[i-1]!=d)fl=1;
		s[i]=s[i-1]+(a[i]-a[1]);
//		cout<<s[i]<<"\n";
//		ss[i]=s[i+1]+;
//		cout<<ss[i]<<"\n";
	}
	if(!fl){
		for(int i=n;i>=1;i--){
			if(n*(n-1)/2*d<=m){
				cout<<i;
				return 0;
			}
		}
	}
//	for(int i=n;i>=1;i--){
////		s[i]=s[i+1]+s[i];
//		cout<<s[i]<<"\n";
//	}
	for(int len=n;len>=1;len--){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			if(len*(a[j]-a[1])-(s[j]-s[i-1])<=m){
				cout<<len;
				return 0;
			}
		}
	}
	return 0;
}

