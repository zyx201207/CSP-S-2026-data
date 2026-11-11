#include<bits/stdc++.h>
using namespace std;
int n;
string s;
char s1;
long long a,cnt;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>s1;
		ans+=a;
		for(int j=1;j<=a;j++){
			s+=s1;
		}
} 
	if(ans%2==0){
		ans/=2;
		ans++;
	}else{
		ans=ans/2+1;
		ans++;
	}
	int len=s.size();
	for(int i=ans-1;i<len;i++){
		if(s[i]!=s[len-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
/*
6 
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/