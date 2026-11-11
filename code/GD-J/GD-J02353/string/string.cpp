#include<iostream>
#include<string>
#include<queue>
using namespace std;
typedef long long ll;
ll ans=0;
string s="%"; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int m;
	cin>>m;
	int n=0;
	for(int i=1;i<=m;i++){
		int val;
		char c;
		cin>>val>>c;
		n+=val;
		for(int j=1;j<=val;j++){
			s=s+c;
		}
	}
	for(int l=1;l<=n/2;l++){
		int r=n-l+1;
		if(s[l]!=s[r]) ans++; 
	}
	cout<<ans<<"\n";
//	cout<<s;
} 
