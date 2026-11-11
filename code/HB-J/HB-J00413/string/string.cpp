#include<bits/stdc++.h>
using namespace std;
int n;
long long a,len=0,ans=0,aaa=0;
char c;
string s="";

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		for(long long i=1;i<=a;i++){
			s+=c;
			len++;
			aaa++;
		}
	}
	for(int i=0;i<(len+1)/2;i++){
		if(s[i]!=s[len-i-1]) ans++;
		aaa++;
	}
	
	cout<<ans<<endl;
	
	return 0;
}
