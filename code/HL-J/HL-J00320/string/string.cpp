#include<bits/stdc++.h>
using namespace std;
int n,a;
string s;
char x;
int main(){
	//freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>x;
		for(int j=1;j<=a;j++) s=s+x;
	}
	int l=s.size();
	int un=l/2,ans=0;
	for(int i=un;i<l;i++){
		if(s[i]!=s[l-i+1])
		ans++;
	}
	cout<<ans;
	return 0;
}
