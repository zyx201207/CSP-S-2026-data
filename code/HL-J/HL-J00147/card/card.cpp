#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5005;
int tong[N];
int n,m;
string s=" ";
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string ss;
		cin>>ss;
		if(s.find(ss)==string::npos) s+=ss;
		else{
			string a;
			for(int i=0;i<s.find(ss);i++) a+=s[i];
			s=a;
		}
		for(int i=0;i<s.size();i++){
			if(s[i]>='0' and s[i]<='9') tong[s[i]-'0']++;
		}
	}
	for(int i=1;i<=m;i++) cout<<tong[i]<<" ";
    return 0;
}
