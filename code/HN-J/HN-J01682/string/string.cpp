#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string s,c;
int a,n,ans=0,l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s='0';
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	l=s.size()-1;
	for(int i=1;i<=l/2+1;i++){
		if(s[i]==s[l+1-i]){
			
		}else{
			s[l+1-i]=s[i];
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
