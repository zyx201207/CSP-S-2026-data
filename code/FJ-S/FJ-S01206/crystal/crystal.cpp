#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n;
long long m;
long long a[N],s[N];
bool ch(int x){
	for(int i=x;i<=n;i++){
		if(a[i]*x-(s[i]-s[i-x])<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n,ans;
	while(l<=r){
		int mid=(l+r)/2;
		if(ch(mid)){
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
