#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200001;
LL n,sum=0;
bool flag=true;
struct S{
	int a;
	char b;
}s[N];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1; i<=n; i++){
     cin>>s[i].a>>s[i].b,sum+=s[i].a;
	if(i>1 && s[i-1].b!=s[i].b)flag=false;
}
if(n==1 || flag==true ||(n==2 && flag==true)){
	cout<<0;
	return 0;
}
else cout<<(n+1)/2;
return 0;
}
