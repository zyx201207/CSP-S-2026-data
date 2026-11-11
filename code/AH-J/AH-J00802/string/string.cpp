#include<bits/stdc++.h>
using namespace std;
long long n,ans,L;
struct node{
	long long len,l,r;
	char ch;
}a[200010];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	a[0].l=0;
	a[0].r=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].ch;
		a[i].l=a[i-1].l+1;
		a[i].r=a[i-1].r+a[i].len;
		L+=a[i].len;
		for(int j=1;j<=a[i].len;j++) s+=a[i].ch;
	}
	for(int i=L-1;i>=(L+1)/2;i--){
		if(s[i]!=s[L-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
