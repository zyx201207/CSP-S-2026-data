#include<bits/stdc++.h>
using namespace std;
long long n,a,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}long long len=s.size();
	long long l=len/2;
	long long i=0;
	while(l!=0){
		if(s[i]!=s[len-i-1]){
			ans++;
		}i++;
		l--;
	}cout<<ans;
	return 0;
}
