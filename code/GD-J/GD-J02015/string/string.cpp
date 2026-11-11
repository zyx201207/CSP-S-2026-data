#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],n,ans=0,zhi,zhii,cnt;
char c[N];
bool yy=1;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]!=c[i-1])
			yy=0;
	}
	if(yy){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-i-1]){
			s[s.size()-i-1]=s[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
//2 a 2 b 1 c
