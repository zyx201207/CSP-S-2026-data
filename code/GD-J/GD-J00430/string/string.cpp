#include<bits/stdc++.h>
using namespace std;
int n;
string s="";
int ans=0,sum=0;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		for(int j=1;j<=a[i];j++){
			s=s+c[i];
		}
	}
	s=' '+s;
	for(int i=1;i<=(sum+1)/2;i++){
		int j=sum-i+1;
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
