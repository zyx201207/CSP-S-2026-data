#include<bits/stdc++.h>
using namespace std;

const int N=2e5+9;

string s="_";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++) s+=c;
	}
	long long L=s.size()-1,ans=0;
	for(long long i=1;i<=L/2;i++)
		if(s[i]!=s[L+1-i]) ans++;
	cout<<ans<<'\n';	
	return 0;
}

