//李昊燃 华东师范附属贵阳学校 GZ-J 00234
#include<bits/stdc++.h>
using namespace std;
long long cnt1,cnt2;
string a;
char b1;
long long x,n,cnt,s,s1,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	if(n==1){
		cout<<0;return 0; 
	}
	for(int i=1;i<=n;i++){
		cin>>x>>b1;
		cnt+=x;
		s=(cnt)/2;
		for(int j=1;j<=x;j++) a+=b1;
	}
	if(cnt%2==0) s1=s+1;
	else s1=s;
	for(int i=0;i<=s;i++){
		if(a[s1+i]!=a[s-i]) ans++;
		//cout<<s1+i<<" "<<s-i<<" "<<a[s1+i]<<" "<<a[s-i]<<"\n";
	}
	cout<<ans;
	return 0;
}
