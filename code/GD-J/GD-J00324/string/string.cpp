#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n=0,m; 
	cin>>n;
	int a;
	char c;
	string s="";
	for(int i=0;i<n;i++){
		cin>>a>>c;
		if(a>50){
			m+=a;
			continue;
		} 
		for(int j=0;j<a;j++) s+=c;
	}
	long long len=s.size(),ans=0;
	for(int i=0;i<len/2;i++) if(s[i]!=s[len-1-i]) ans++;
	if(m!=0) ans=m/2;
	cout<<ans;
	return 0; 
}
