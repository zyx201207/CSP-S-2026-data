//GZ-J00655 胡中睿
#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		string a;
		cin>>x>>a;
		for(int i=1;i<=x;i++){
			s+=a;
		}
	}
	for(int i=0;i<s.length()/2;i++)
	{
		if(s[i]!=s[s.length()-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
