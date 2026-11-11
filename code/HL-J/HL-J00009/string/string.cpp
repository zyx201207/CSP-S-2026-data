#include<bits/stdc++.h>
using namespace std;
int n,x,len,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n;
	while(n--){
		cin>>x>>c;
		while(x--){
			s+=c;
		}
	}
	len=s.size();
	for(int i=0;i<len/2;i++) if(s[i]!=s[len-i-1]) ans++;
	cout<<ans;
	return 0;
}