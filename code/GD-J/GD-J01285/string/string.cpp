#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,i,a,j,sum=0,len,q;
	char c;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a>>c;
		for(j=1;j<=a;j++){
			s+=c;
		}
	}
	len=s.size();
	for(i=(len-1)/2;i>=0;i--){
		q=len-i-1;
		if(s[i]!=s[q])sum++;
	}
	cout<<sum;
	return 0;
}
