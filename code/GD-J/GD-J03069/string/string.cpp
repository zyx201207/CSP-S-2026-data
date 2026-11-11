#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
long long len;
long long a[200005];
char c[200005];
long long cnt=0;
long long ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			ans+=min(a[l],a[r]);
			long long minn=min(a[l],a[r]);
			a[l]-=minn;
			a[r]-=minn;
		}else{
			long long minn=min(a[l],a[r]);
			a[l]-=minn;
			a[r]-=minn;
		}
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<ans;
	return 0;
}
