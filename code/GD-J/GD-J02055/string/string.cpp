#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N];
string s[N];
int sum1[N],sum2[N];
int len;
int n;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		sum1[i]=sum1[i-1]+a[i];
	}
	for(int i=n;i>=1;i--){
		sum2[i]=sum2[i+1]+a[i];
	}
	int ans=0;
	int l=1,r=n;
	while(l<r){
		if(s[l]!=s[r]){
			int m=min(sum2[r],sum1[l]),n=max(sum1[l-1],sum2[r+1]);
			ans+=m-n;
		}
		if(sum1[l]<sum2[r]) l++;
		else if(sum1[l]==sum2[r]){
			l++,r--;
		}
		else r--;
	}
	cout<<ans<<endl;
	return 0;
}
