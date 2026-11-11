#include<bits/stdc++.h>
using namespace std;
long long n,x,ans;
char c;
map<long long,string> a;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			s.push_back(c);
		}
	}
	for(int i=0;i<s.size();i++){
		for(int j=s.size()-1;j>=0;j--){
			if(s[i]!=s[j]){
				ans++;
				s.erase(j,1);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 
