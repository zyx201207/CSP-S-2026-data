#include<iostream>
using namespace std;
long long n,a;
char s[5000000],c,x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s[x]=c;
			x++;
		}
	}
	a=0;
	for(int i=x-1;i>=0;i--){
		if(s[i]!=s[x-i-1]){
			a++;
		}
	}
	cout<<a/2;
	return 0;
}
