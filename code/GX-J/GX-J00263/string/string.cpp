#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x;
	char y;
}a[200005];
int n,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int m=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		if(n==1){
			cout<<0;
			return 0;
		}
		m+=a[i].x;
		for(int j=1;j<=a[i].x;j++){
			s+=a[i].y;
		}
	}
	m/=2;
	int cnt=0,l=s.size()-1;
	while(cnt<=m){
		if(s[cnt++]!=s[l--]) ans++;
	}
	cout<<ans;
	return 0;
}
