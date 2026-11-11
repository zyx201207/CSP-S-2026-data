//GZ-J00707 贵阳市第九中学 陈诗语
#include<bits/stdc++.h>
using namespace std;
int n,b,a;
char c;
string s;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	for(int i=0,j=s.size()-1;i<=j;i++,j--){
		if(s[i]!=s[j]){
			s[j]=s[i];
			b++;
		}
	}
	cout<<b;
	return 0;
} 
