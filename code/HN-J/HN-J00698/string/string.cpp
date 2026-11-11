#include<bits/stdc++.h>
using namespace std;
unsigned long long n,x[200005],ans,len;
char c[200005];
string s=" ";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>c[i];
		for(int j=1;j<=x[i];j++){
			s+=c[i];
		}
	}
	len=s.size();
	for(int i=1;i<=len/2;i++){
		if(s[i]!=s[len-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
