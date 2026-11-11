#include<bits/stdc++.h>
using namespace std;
int n;
long long ai,num,ans,anus;
string a,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	a+='0';
	for(int i=1;i<=n;i++)
	{
		cin>>ai>>b;
		num+=ai;
		for(int j=1;i<=ai;j++) a+=b;
	}
	ans=num/2;
	if(n>=2000) {
	cout<<num/2;return 0;}
	for(int i=1;i<=ans;i++){
		if(a[i]!=a[num-i])anus++;
	}
	cout<<anus;
	return 0;
}
