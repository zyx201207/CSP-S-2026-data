#include <bits/stdc++.h>
using namespace std;
long long n,a,cnt=0,ans=0;
string s,s1,s2,s3;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a>>s;
		cnt+=a;
		for(int j=1;j<=a;j++){
			s1=s1+s;
		}
	}
	for(int i=1;i<=cnt/2;i++){
		if(s1[i]==s1[cnt-i+1]){
			cnt+=0;
		}else{
			cnt+=1;
		}
	}
	cout <<ans+1;
	return 0;
}
