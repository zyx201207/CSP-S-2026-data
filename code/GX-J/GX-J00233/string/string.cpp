#include<bits/stdc++.h>
using namespace std;
long long n,a,ans=0;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		s.append(a,c);
	}
	for(int i=0,j=(int)s.size()-1;i<=(int)s.size()/2;i++,j--) if(s[i]!=s[j]) ans++;
	cout<<ans;
	return 0;
}
