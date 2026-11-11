#include<bits/stdc++.h>
using namespace std;
long long n,a,ans,tmp;
char b;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>b;
		for(long long j=1;j<=a;j++){
			s+=b;
			ans++;
		}
	}
	if(ans%2==1){
		for(long long i=0;i<=(ans-1)/2;i++){
			if(s[i]!=s[ans-i-1]){
				tmp++;
			}
		}
	}else{
		for(long long i=0;i<=ans/2;i++){
			if(s[i]!=s[ans-i-1]){
				tmp++;
			}
		}
	}
	cout<<tmp;
	return 0;
}
