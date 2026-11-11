#include<bits/stdc++.h>
using namespace std;
string s=" ";
int n,a,ans=0;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++) s+=c;
	}
	int len=s.size()-1,mid=(len+1)/2;
	for(int i=mid;i<=len;i++){
		if(s[i]!=s[len-i+1]) ans++;
	}
	cout<<ans;
	return 0;
}

