#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
char b[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n=0,s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
		s+=a[i];
	}
	int l=1,r=n;
	int cnt=0,sum=0;
	while(1){
		if(b[l]==b[r])
		cnt+=min(a[l],a[r]);
		int k=min(a[l],a[r]);
		sum+=k;
		a[l]-=k;
		if(a[l]==0){
			l++;
			if(l==r)
			break;
		}
		a[r]-=k;
		if(a[r]==0){
			r--;
			if(l==r)
			break;
		}
	}
	int m=sum-cnt;
	cout<<m;
	return 0; 
} 
