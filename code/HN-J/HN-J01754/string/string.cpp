#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
string s="";
char q;
bool f=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		if(i==1){
			q=c;
		}
		for(int j=1;j<=a;j++){
			s=s+c;
		}
		if(c==q){
			f=1;
		}
		else{
			f=0;
		}
	}
	if(f){
		cout<<0;
		return 0;
	}
	long long l=s.size();
	for(int i=0;i<=l;i++){
		if(s[i]!=s[l+1-i]){
			s[l+1-i]=s[i];
			ans++;
		}
	}
	cout<<ans-1;
	return 0;
}
