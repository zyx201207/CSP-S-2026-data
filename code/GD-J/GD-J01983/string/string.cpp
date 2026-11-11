#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1010011],ans,x=0,op,y,b[1010101];
char c[1010111];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=n;i>=1;i--) b[i]+=b[i+1]+a[i];
	for(int i=1;i<=n;i++) a[i]+=a[i-1];
	int l=1,r=n;
	for(;l<=n,r>=1;){
		int xx=a[l]-x;
		int yy=b[r]-x;
		if(c[l]!=c[r]){
			ans+=min(xx,yy);
			x+=min(xx,yy);
			if(xx==yy) l++,r--;
			else if(xx>yy) r--;
			else if(xx<yy) l++;
		}else{
			x+=min(xx,yy);
			if(xx==yy) l++,r--;
			else if(xx>yy) r--;
			else if(xx<yy) l++;
		}
	}cout<<ans/2;
}

