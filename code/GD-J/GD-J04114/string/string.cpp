#include<bits/stdc++.h>
using namespace std;
long long n,lf=1,ri,ans,minn;
string s[200005];
int a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ri=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	while(lf<ri){
		minn=INT_MAX;
		if(a[lf]==0) lf++;
		if(a[ri]==0) ri--;
		if(s[lf]==s[ri]){
			minn=min(a[lf],a[ri]);
			a[lf]-=minn;
			a[ri]-=minn;
		}else{
			minn=min(a[lf],a[ri]);
			a[lf]-=minn;
			a[ri]-=minn;ans+=minn;
		}
	}
	cout<<ans;
	return 0;
}

