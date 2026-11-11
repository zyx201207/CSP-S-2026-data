#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef pair<int,int> PII;
const int N=2e5+10;
int a[N];
char c[N];
bool palin(string s){
	string t=s;
	reverse(s.begin(),s.end());
	return s==t;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,mx=0;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		mx=max(mx,a[i]);
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	if(mx<=500){
		int len=s.size();
		ll ans=0;
		int l=(len%2==1?len/2:len/2-1),r=len/2;
		for(int i=0;i<=len/2;i++){
			if(s[l-i]!=s[r+i]){
				ans++;
			}
		}
		cout<<ans;
	}else{
		
	}
	return 0;
}
