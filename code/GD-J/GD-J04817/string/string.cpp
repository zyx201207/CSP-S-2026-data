#include<bits/stdc++.h>
#define ll long long 
using namespace std;
//const int N=2e5+5;
//ll a[N]={0};
//char c[N];
unsigned ll ans=0;
string s;
int main(){
		freopen("string.in","r",stdin);
		freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		//cin>>a[i];cin>>c[i];
		ll a;
		char c;
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	unsigned ll l=0;
	unsigned ll r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r])ans++;
		l++,r--;
	}
	cout<<ans<<endl;
	return 0;
}
