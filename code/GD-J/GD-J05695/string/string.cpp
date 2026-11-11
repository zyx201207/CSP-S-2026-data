#include<bits/stdc++.h>
using namespace std;
int n,a,r,ans;
string s;
char x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>x;
		for(int j=1;j<=a;j++){
			s+=x;
		}
	}a=s.size();
	r=a-1;
	if(a%2==0) n=1;
	else n=0;
	for(int l=0;l<=a/2-n;l++){
		if(s[l]!=s[r]){
			ans++;
		}r--;
	}cout<<ans;
	return 0;
}
