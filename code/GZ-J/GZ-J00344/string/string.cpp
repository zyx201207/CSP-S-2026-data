//GZ-J00344 遵义市第十九中学 丁钧泽 
#include<bits/stdc++.h>
using namespace std;
long long a[100000005];
string s_1[10000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,x=0;
	cin>>n;
	string s,c;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s_1[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=s_1[i];
		}
	}
	for(int i=s.size()-1;i>=0;i--){
		c+=s[i];
	}
	if(c==s){
		cout<<0;
		return 0;
	}else{
		for(int i=0;i<s.size();i++){
			if(s[i]!=c[i]){
				x++;
			}
		}
	}
	cout<<x/2;
	return 0;
} 
