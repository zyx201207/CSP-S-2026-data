#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5; 
int n;
struct E{
	ll x;
	char c;
}a[N];
ll sum,sga;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		sum+=a[i].x;
	}
	if(sum<=1e8){
		char dh=' ';
		s.push_back(dh);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i].x;j++) {
				s.push_back(a[i].c);
			}
		}cout<<s<<'\n';
		for(int i=1;i<s.length();i++){
			if(s[i]!=s[s.length()-i]){
				sga++;
			}
		}cout<<sga<<" ";
	}else{
		cout<<sum/2;
	}
	return 0;
}
