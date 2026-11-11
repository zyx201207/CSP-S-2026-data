//GZ-t00611 北京师范大学贵阳附属中学 陆志嘉 
#include<bits/stdc++.h>
using namespace std;
long long  c=0,cnt=0;
long long d(string s){
	for(int i=0;i<=c-1;i++){
		if(s[i]!=s[c-i-1]){
			cnt++;
			s[c-i-1]=s[i];
		}
	}
	return cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a;
		
		cin>>b;
		c+=a;
		
		for(int j=1;j<=a;j++){
			s=s+b;
		}
	}
	
	cout<<d(s);
	return 0;
}
