#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int ans;
int a,n[200010];
char m[200010];
string s; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>n[i]>>m[i];
	}
	for(int i=1;i<=a;i++){
		for(int j=1;j<=n[i];j++){
			s+=m[i];
		}
	}
	int len=s.length();
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]) ans++;
	}
	cout<<ans;
    fclose(stdin);
    fclose(stdout);
		return 0;
}
