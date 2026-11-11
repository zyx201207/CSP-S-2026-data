#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long hw_if(string a){
	long long sum=0,len=a.size();
	string b="";
	for(int i=len-1;i>=0;i--){
		b+=a[i];
	}
	for(int i=0;i<len/2;i++){
		if(a[i]==b[i]){
			sum++;
		}
	}
	return (len/2-sum);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		string z="";
		cin>>x;
		cin>>y;
		for(int j=1;j<=x;j++){
			z+=y;
		}
		//a[i]=z;
		s+=z;
	}
	cout<<hw_if(s);
	return 0;
}
