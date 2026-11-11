#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int n;
	scanf("%lld",&n);
	long long int a[n+5]={0},i=1,p=0,j,l,r;
	string s;
	char h;
	for(;i<=n;i++){
		scanf("%lld %c",&a[i],&h);
		string t(a[i],h);
		s+=t;
	}
	if((s.size()%2)==0){
		l=s.size()/2-1,r=s.size()/2;
	}
	else{
		l=s.size()/2-1,r=s.size()/2+1;
	}
	for(;l>=0&&r<s.size();l--,r++){
		if(s[l]!=s[r]){
			p++;
		}
	}
	cout<<fixed<<setprecision(0)<<p<<endl;
	return 0;
}
