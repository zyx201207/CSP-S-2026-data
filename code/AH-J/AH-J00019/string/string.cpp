#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int m,ans,f[N][N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>m;
	for(int i=1,d;i<=m;i++){
		char c;
		cin>>d>>c;
		for(int j=1;j<=d;j++){
			s+=c;
			if(s.size()>1e8){
				cout<<0;
				return 0;
			}
		}
	}
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]!=s[n-i-1]) ans++;
	}
	cout<<ans/2;
	return 0;
}
//理想72分
