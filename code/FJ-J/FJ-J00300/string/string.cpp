#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[200005],sum=0,mid,ans=0;
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n; 	
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		mid+=a[i];
	}
	mid/=2;
	int l=1,r=n;
	while(mid){
	int m=min(min(a[l],a[r]),mid);
		if(s[l]!=s[r]){
			ans+=m;
		}
		mid-=m;
		a[l]-=m;
		a[r]-=m;
		if(!a[l])l++;
		if(!a[r])r--;
	}
	cout<<ans;
	return 0;
}
