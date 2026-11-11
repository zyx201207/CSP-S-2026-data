#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	string b,s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s += b;
		}
	}
	string l,c,d;
	int x;
	if(s.size()%2==0){
		x=s.size()/2;
		for(int i=x;i>=1;i--){
			d+=s[i];
		}
		for(int i=0;i<=x-1;i++){
			c+=s[i];
		}
		cout<<d.size();
	}
	else{
		x=s.size()/2+1;
		for(int i=x-1;i>=0;i--){
			d+=s[i];
		}
		for(int i=0;i<=x-2;i++){
			c+=s[i];
		}
		cout<<d.size();
	}

	return 0;
}
