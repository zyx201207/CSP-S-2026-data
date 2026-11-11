#include<bits/stdc++.h>
using namespace std;
int n,a;
char c;
string s;
long long ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
//	cout<<s<<endl;
	long long lens=s.size();
	for(long long i=0;i<lens/2;i++){
		if(s[i]!=s[lens-i-1]) ans++;
	}
	
	cout<<ans;
	return 0;
}
