#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct tong{
	ll n;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s="",ss;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].n>>a[i].c;
		for(int j=1;j<=a[i].n;j++){
			s+=a[i].c;
		}
	}
	ll l=s.size(),cnt=0;
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-1-i])cnt++;
	}
	cout<<cnt<<"\n";
	
	
	return 0;
} 
