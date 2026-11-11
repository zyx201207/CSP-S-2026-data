//GZ-J00700 陈梓灿 遵义市第四初级中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
long long n,a;
string s="";
char c;
cin>>n;
for(long long i=0;i<n;i++){
	cin>>a>>c; 
	for(long long j=0;j<a;j++){
		s=s+c;
	}
}
int p=s.size()-1,b=0;
for(long long i=0;i<s.size()/2;i++){
	if(s[i]!=s[p]){
		b++;
	}
	p--;
}
cout<<b;
	return 0;
}

