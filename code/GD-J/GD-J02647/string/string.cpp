#include<iostream>
#include<cstring>
using namespace std;
long long n,a,c=0;
char b,ss=' ';
string s="";
bool f=true;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		if(ss==' ')f=true;
		else if(ss!=b)f=false;
		for(int j=1;j<=a;j++){
			s+=b;
		}
		ss=b;
	}
	if(f){
		cout<<0;
		return 0;
	}
	long long l=s.size();
	for(long long i=0;i<=(l-1)/2;i++){
		if(s[i]!=s[l-i-1])c++;
	}
	cout<<c;
}
