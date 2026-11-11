#include<bits/stdc++.h> 
#define int long long
using namespace std;
int n;
string s="0";
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int sum=0,ans=0;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		sum+=a;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	for(int i=1;i<=sum/2;i++)
		if(s[i]!=s[sum-i+1])
			ans+=1;
	cout<<ans<<endl;
	return 0;
}
