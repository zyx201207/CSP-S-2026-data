#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,x,y,z) for(int i=x;i<=y;i+=z)
const int N=2e5+10;
int n,a[N],ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;FOR(i,1,n,1)cin>>a[i]>>c[i];
	int l=1,r=n;while(l<r){
		if(c[l]==c[r]){
			if(a[l]<=a[r])a[r]-=a[l],l++;
			else a[l]-=a[r],r--;
		}else{
			if(a[l]<=a[r])a[r]-=a[l],ans+=a[l++];
			else a[l]-=a[r],ans+=a[r--];
		}
	}cout<<ans;
	return 0;
}

