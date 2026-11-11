#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
long long a[500005];
long long s[500005],m,n;
bool qq(int x,int y){
	int d=(s[x]-s[y])-(a[x]-a[y])*(y-1); 
	return (d<=m); 
}
int r(int x){
	int l=1,r=x;
	int ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(qq(x,mid)==true){
			r=mid-1;
			ans=(x-mid)+1;
		}else{
			l=mid+1;
		}
	}
	return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=(a[i]-a[i-1])+s[i-1]+(i-2)*(a[i]-a[i-1]);
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		int d=r(i);
		maxn=max(maxn,d);
	}	
	cout<<maxn;
	return 0;
}
