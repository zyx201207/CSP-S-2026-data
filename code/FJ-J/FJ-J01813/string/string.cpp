#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,l,r,cnt;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	l=1;
	r=n;
	while(l<r){
		if(b[l]!=b[r]){
			ans+=min(a[l],a[r]);
			cnt=min(a[l],a[r]);
			a[l]-=cnt;
			a[r]-=cnt;
			if(a[l]==0){
				l++;
			}
			if(a[r]==0){
				r--;
			}
		}else{
			cnt=min(a[l],a[r]);
			a[l]-=cnt;
			a[r]-=cnt;
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
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
