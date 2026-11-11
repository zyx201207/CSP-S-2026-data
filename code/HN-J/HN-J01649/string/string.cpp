#include<bits/stdc++.h>
using namespace std;
#define int long long
struct g{
	int s;
	char c;
}an[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>an[i].s>>an[i].c;
	}
	int ans=0;
	string ss="";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=an[i].s;j++)ss+=an[i].c;
	}
	for(int i=0,j=ss.size()-1;i<=j;i++,j--){
		if(ss[i]!=ss[j])ans++;
	}
	cout<<ans;
	return 0;
} 
