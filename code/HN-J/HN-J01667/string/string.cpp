#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll a[N];
int ch[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		char cha;cin>>cha;
		ch[i]=cha-'a'+1;
	}
	ll ans=0;
	int l=1,r=n;
	while(l<r){
		ll mn=min(a[l],a[r]);
		if(ch[l]!=ch[r])ans+=mn;
		a[l]-=mn,a[r]-=mn;
		if(!a[l])l++;
		if(!a[r])r--;
	}
	cout<<ans;
	return 0;
}
/*
一眼DP，实则诈骗

回文修改只需看有几对位置不同即可

那我们考虑双指针 
*/
