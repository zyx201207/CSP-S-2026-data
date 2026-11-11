#include <bits/stdc++.h>
using namespace std;
long long n,l,len=1,ans;
char c;
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l>>c;
		for(int j=len;j<len+l;j++){
			s[j]=c;
		}
		len+=l;
	}
	for(int i=1;i<=len-i;i++){
		if(s[i]!=s[len-i]){
			ans+=1;
		}
	}
	cout<<ans;
	return 0;
}
