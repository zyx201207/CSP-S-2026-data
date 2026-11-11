#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200002];
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0,pos=0,ans=0;
	cin>>n;
	s.push_back('-');
	//Test 1 ~ 12,13 ~ 21 64pts
	for(int i=1;i<=n;i++){
		char c;
		cin>>a[i]>>c;
		sum+=a[i];
		for(int j=1;j<=a[i];j++)
			s.push_back(c);	
	} 
	for(int i=1;i<=sum/2;i++){
		if(s[i]!=s[sum-i+1]){
			//cout<<s[i]<<" "<<s[sum-i+1]<<endl;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
//miao ~
//++ RP 
//RP ++ 
// ~64 pts
//All ~164 pts
