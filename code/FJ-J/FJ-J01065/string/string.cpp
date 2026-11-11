#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
string s="";
int n;
long long num=0;
long long sum=0;
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i]>>c[i];
	num+=a[i];
	for(int j=1;j<=a[i];j++){
		s+=c[i];
	}
}
for(int i=num/2-1;i>=0;i--){
	if(s[num-i-1]!=s[i]){
		sum++;
	}
}
cout<<sum;
return 0;
 } 
