#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
long long n,m;
long long s[10000010];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(long long i=1;i<=n;i++){
	cin>>s[i];
}
cout<<s[n];
return 0;
}
