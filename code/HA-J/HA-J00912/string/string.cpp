#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,ans=0;
	char o,u;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld%c%c",&a,&u,&o);
		for(int j=1;j<=a;j++){
			s+=o;
		}
	}
	for(int i=0;i<=((long long)(s.size())+1)/2-1;i++){
		if(s[i]!=s[(long long)(s.size())-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
