#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,sum,ans;
vector<char>v;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		sum+=a;
		while(a--){
			v.push_back(c);	
		}
	}
	int m=sum/2;
	for(int i=0;i<m;i++){
		if(v[i]!=v[sum-i-1])ans++;
	}
	cout<<ans;
	return 0;
}
