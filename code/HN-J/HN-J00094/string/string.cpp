#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[200005];
char c[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n,cnt=0;
	while(l<r){
		if(c[l]!=c[r]){
			if(a[l]<=a[r])cnt+=a[l],a[r]-=a[l],l++;
			else cnt+=a[r],a[l]-=a[r],r--;
		}else{
			if(a[l]<=a[r])a[r]-=a[l],l++;
			else a[l]-=a[r],r--;
		}
	}
	cout<<cnt;
	return 0;
} 
