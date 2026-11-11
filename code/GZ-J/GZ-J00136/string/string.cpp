//GZ-J00136 遵义市第十二中学  李明博 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,x,num=0,m=0;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>x;
		char s;
		cin>>s;
		a+=x*s;
		num+=x;
	}
	if(n==1)cout<<0;
	ll j=num;
	for(ll i=0;i<=num/2;i++){
		if(a[i]!=a[j])m++;
		j--;
	}
	cout<<m;
	fclose(stdin);fclose(stdout);
	return 0;
}
