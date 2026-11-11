#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
int n;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		int ai;char c;
		cin>>ai>>c;
		sum+=ai;
		for(int i=1;i<=ai;i++){
			s+=c;
		}
	}
	int ans=0;
	int l=0;
	while(l<=sum/2){
		int r=sum-l-1;
		if(s[l]!=s[r])ans++;
		l++;
	}
	cout<<ans;
	return 0;
} 
