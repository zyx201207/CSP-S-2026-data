#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+7;
int k[N]={};
char s[N]={};
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		char v;
		cin>>t>>v;
		cnt+=t;
		k[i]=t;
		s[i]=v;
	}int ans=0;
	int l=0,r=n-1;
	while(l<=r){
		if(s[l]!=s[r])ans+=min(k[l],k[r]);
		if(k[l]>k[r])k[l]-=k[r],r--;
		else k[r]-=k[l],l++;
	}cout<<ans;
	return 0;
} 
