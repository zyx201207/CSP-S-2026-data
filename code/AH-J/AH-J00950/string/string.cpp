#include<bits/stdc++.h>
using namespace std;
long long n,a,ans;;
char c;
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long i,j;
	for(i=1;i<=n;i++){
		cin>>a>>c;
		for(j=1;j<=a;j++){
			s+=c;
		}
	}
	long long l=s.size();
	for(i=l-1;i>=0;i--){
		s1+=s[i];
	}
	if(l%2==0){
		for(i=0;i<l/2;i++){
			if(s[i]!=s1[i]){
				ans++;
			}
		}
	}else{
		for(i=0;i<(l+1)/2;i++){
			if(s[i]!=s1[i]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
