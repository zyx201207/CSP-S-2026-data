#include<bits/stdc++.h>
using namespace std;
int n;
long long l,ans;
string s,t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		int a;
		string c;
		cin>>a>>c;
		l+=a;
		for(int i=1;i<=a;i++)
			s+=c;
	}
	t=s;
	reverse(s.begin(),s.end());
	for(int i=0;i<(l+1)/2;i++){
		if(s[i]!=t[i]) ans++;
	}
	cout<<ans;
	return 0;
}
