#include<iostream>
#include<string>
using namespace std;
#define int long long

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int t;
		string z;
		cin>>t>>z;
		while(t--)s+=z;
	}
	int ans=0;
	int m=s.size();
	for(int i=0;i<m/2;i++){
		if(s[i]!=s[m-i-1]){
			ans++;
		}
	}
	cout<<ans;
}
