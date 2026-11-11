#include<bits/stdc++.h>
using namespace std;
string s,s1,s2;
int n;
long long sun;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		while(a--){
			s+=b;
		}
 }
	if(s.size()%2==0){
		int y=s.size()/2-1;
		int u=s.size()-1;
		for(int i=0;i<=y;i++)s1+=s[i];
		for(int i=y+1;i<=u;i++)s2+=s[i];
		for(int i=0,j=y;j-i>0;i++,j--){
			if(s1[i]!=s2[j])sun++;
		}
	}
	else {
		int y=s.size()/2-1;
		int u=s.size()-1;
		for(int i=0;i<=y;i++)s1+=s[i];
		for(int i=y+2;i<=u;i++)s2+=s[i];
		for(int i=0,j=y;j!=s.size()/2&&i!=s.size()/2;i++,j--){
			if(s1[i]!=s2[j])sun++;
		}
	}
	cout<<sun;
	return 0;
}
