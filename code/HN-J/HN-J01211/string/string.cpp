#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200005],s[200005];
char c[200005];
int szk(int x){
	int l=1,r=n,ans=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(x<=s[mid]){
			ans=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return ans;
}
int shz(int x,int k){
	return s[k]-x;
}
int sqz(int x,int k){
	return x-s[k-1]-1;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s[i]=s[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=(s[n]-i+1);i++){
		int zki=szk(i);
		int zni=szk(s[n]-i+1);
		if(c[zki]!=c[zni]){
			ans+=min(sqz(s[n]-i+1,zni),shz(i,zki))+1;
			i+=min(sqz(s[n]-i+1,zni),shz(i,zki));
		}else{
			i+=min(sqz(s[n]-i+1,zni),shz(i,zki));
		}
	}
	cout<<ans;
	return 0;
}

