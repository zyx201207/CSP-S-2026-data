#include<bits/stdc++.h>
using namespace std;
long long n,a,sum,l;
string s,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		l+=a;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]) sum++;
	}
	cout<<sum;
	return 0;
}
