#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
const ll N=2e6+10,M=5e3+10;
ll n,a[N],ans,sum;string c,s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		for(int i=1;i<=a[i];i++)s+=c;
		sum+=a[i];
	}
	for(int i=1;i<=(sum+1)/2;i++){
		if(s[i]!=s[sum-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
