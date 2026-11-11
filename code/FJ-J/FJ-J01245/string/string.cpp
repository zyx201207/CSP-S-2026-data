#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			long long minn=min(a[l],a[r]);
			ans+=minn;
			a[l]-=minn;
			a[r]-=minn;
			if(a[l]==0){
				l++;
			}
			if(a[r]==0){
				r--;
			}
		}else{
			long long minn=min(a[l],a[r]);
			a[l]-=minn;
			a[r]-=minn;
			if(a[l]==0){
				l++;
			}
			if(a[r]==0){
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
