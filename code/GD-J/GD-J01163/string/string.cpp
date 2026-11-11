#include<bits/stdc++.h>
using namespace std;
long long n,a,ans,sum;
string s=" ",s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>s1;
		sum+=a;
		for(long long i=1;i<=a;i++){
			s+=s1;
		}
	}
	for(long long i=sum;i>=(sum+1)/2;i--){
		if(s[i]!=s[sum+1-i]){
			s[i]=s[sum+1-i];
			ans++;			
		}
	}
	cout<<ans;
	return 0;
}
