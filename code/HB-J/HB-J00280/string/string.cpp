#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
string x;
void fz(string &x){
	string new_;
	int len = x.length();
	for (int i= len-1 ; i>=0;i--)
		new_+=x[i];
	x= new_;
	return ;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		int a;
		char b;
		cin>>a>>b;
		for (int j=0;j<a;j++)
			x+=b;
	}
	int len= x.length();
	int ans=0;
	if( len %2 ==0 ){
		string a1=x.substr(0,len/2);
		string a2=x.substr(len/2,len/2);
		fz(a2);
		
		for (int i=0;i<len/2;i++){
			if (a1[i] != a2[i])
				ans++;
		}
	}
	else {
		string a1=x.substr(0,len/2);
		string a2=x.substr(len/2+1,len/2);
		fz(a2);
		for (int i=0;i<len/2;i++){
			if (a1[i] != a2[i])
				ans++;
		}
		
		
	}
	cout<<ans;
	return 0;
}
