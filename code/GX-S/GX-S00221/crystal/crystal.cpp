#include <bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
const int N=5e5+10;
int n,m,ans,a[N],s[N];


signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(); m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	// for(int i=n;i>=1;i--){
	// 	if(a[i]*i-s[i]<=m){
	// 		cout<<i<<endl;
	// 		break;
	// 	}
	// }
	int l=1;
	for(int r=1;r<=n;r++){
		if(a[r]*(r-l+1)-(s[r]-s[l-1])<=m)
			ans=max(ans,r-l+1);
		else{
			// cout<<l<<" "<<r<<endl;
			// cout<<a[3]*2-(s[3]-s[1])<<endl;
			for(int i=l;i<=r;i++){
				if(a[r]*(r-i+1)-(s[r]-s[i-1])<=m){
					l=i;
					ans=max(ans,r-l+1);
					break;
				}
			}
			// cout<<l<<" "<<r<<endl;
		}
	}
	cout<<ans<<endl;


	return 0;
}