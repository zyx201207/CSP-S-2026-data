#include<bits/stdc++.h>
using namespace std;
struct q{
	long long a;
	char b;
};
q a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long s=0;
	int n;
	string c;
	cin>>n;
	while(n--){
		cin>>a.a>>a.b;
		for(int j=0;j<a.a;j++){
			c+=a.b;
		}
	}
	for(int i=0;i<c.size()/2;i++){
		if(c[i]!=c[c.size()-i-1]){
			s++;
		}
	}
	cout<<s;
	return 0;
} 
