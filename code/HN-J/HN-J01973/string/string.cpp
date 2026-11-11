#include<bits/stdc++.h>
using namespace std;
int n,a[100001],sum;
string s; 
char c[100001];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin >> n;
for(int i=1;i<=n;i++){
	cin>>a[i]>>c[i];
	for(int j=1;j<=a[i];j++){
		s+=c[i];
	}
}
//cout<<s <<" "<< s.size()<<s[4];

for(int i=0;i<s.size()/2+1;i++){
	sum+=s[i]!=s[s.size()-i-1];
}
cout << sum;
return 0;
}
