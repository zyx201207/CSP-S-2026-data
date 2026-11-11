#include<bits/stdc++.h>
#include<string>
using namespace std;
int n;
long long l,a[200020],g=1,c;
string b=" ";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		string s;
		cin>>x>>s;
		a[i]=x;
		for(int j=1;j<=x;j++){
			b=b+s;
			g++;	
		}
		l+=x;
	}
	for(int i=1;i<=l/2;i++){
		if(b[i]!=b[l-i+1]){
			c++;
		}
	}
	cout<<c;
	return 0;
}

