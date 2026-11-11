#include<bits/stdc++.h>
using namespace std;
char s;
string s1,s2;
int ans=1,n,a,f=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>s;
		for(int i=1;i<=a;i++)s1+=s;
	}
	int len=s1.size();
	for(int i=len-1;i>0;i--){
		s2+=s1[i];
	}
	s2+=s1[1];
	for(int i=0;i<len;i++){
		if(s2[i]!=s1[i]){
			f=0;
		}
	}
	if(f==1)cout<<0;
	return 0;
}
