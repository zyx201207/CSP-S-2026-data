//GZ_S00174 北京师范大学贵阳附属中学 李培源
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long a[N],m,s[N];
bool check(int lon){
	for(int r=n;r>=lon;r--){
		if(lon*a[r]<=(m+s[r]-s[r-lon])){
			return 1;
		}
	}
	return 0;	
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		} 
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;	
}
