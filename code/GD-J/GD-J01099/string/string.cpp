#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[1000005];
char b[1000005];
long long sum;
string s;
long long c[80],sss;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i]>>b[i];
	for(int j=1;j<=a[i];j++){
		s+=b[i];
	}
	c[b[i]-96]++;
}
for(int i=1;i<=26;i++){
	if(c[i]!=0){
		sss++;
	}
}
if(sss==1){
	cout<<0;
	return 0;
}
long long l=0,r=s.size()-1;
while(l<=r){
	if(s[l]!=s[r]){
		sum++;
	}
	l++,r--;
}
cout<<sum;
return 0;
}

