#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long l[N],r[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0,len=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		len+=a;
		for(int k=1;k<=a;k++){
			s+=c;
		}
	}
	s=' '+s;
	//cout<<s<<"\n";
	for(int i=1;i<=len/2;i++){
		if(s[i]!=s[len+1-i]){
			//cout<<s[i]<<" "<<s[len+1-i]<<"\n";
			++ans;
		}
	}
	cout<<ans;
	return 0;
} 
// s[i]=s[L+1-i]
