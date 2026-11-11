#include<iostream>
#include<cstdio>
using namespace std;
int a,ans,n;
char b;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s+=b;
		}
	}
	int l=0,r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

