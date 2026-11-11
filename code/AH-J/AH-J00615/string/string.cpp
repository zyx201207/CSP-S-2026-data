#include<bits/stdc++.h>
using namespace std;
string s;int n;long long sum=0,ma=-1,ss=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;char c;
		cin>>a;cin>>c;
		ma=max(ma,1ll*a);ss+=a;
		if(a<=60)for(int i=1;i<=a;i++) s+=c;
	}int len=s.size();
	if(ma>60){cout<<ss/2;return 0;}
	for(int i=0;i*2<len;i++){
		if(s[i]!=s[len-i-1]) sum++;
	}cout<<sum;
	return 0;}
