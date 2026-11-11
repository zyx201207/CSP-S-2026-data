#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
struct node{
	int b;
	char c;
}a[N];
ll n,ans,sum;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].b>>a[i].c;
		sum+=a[i].b; 
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=a[i].b;j++)
			s+=a[i].c;
	for(ll i=0;i<sum/2;i++)
		if(s[i]!=s[n-i]) ans++;
	cout<<ans;
	return 0;
}

