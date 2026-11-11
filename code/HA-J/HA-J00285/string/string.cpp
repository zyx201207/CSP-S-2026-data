#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	cin>>t;
	string s="",m="";
	int n[200010]={0},c=0,k=0;
	while(t--){
		char l;
		k++;
		cin>>n[k]>>l;
		if(k==1) c=n[k];
		else c=__gcd(c,n[k]);
		m+=l;
	}
	for(int i=1;i<=k;i++) n[i]/=c;
	int a=0;
	for(int i=0;i<m.size();i++) for(int j=1;j<=n[i+1];j++) s+=m[i];
	for(int i=0;i<=s.size()/2;i++) if(s[i]!=s[s.size()-1-i]) a++,s[i]=s[s.size()-1-i];
	cout<<a*c;
}
