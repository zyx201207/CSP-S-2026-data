#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
string s="";
int ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	while(n--){
		int k=0;
		char m=0;
		cin>>k;
		cin>>m;
		for(int i=1;i<=k;i++){
			s+=m;
		}
	}
	int k=s.size();
	for(int i=0;i<k/2;i++){
		if(s[i]!=s[k-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

