#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",std.in);
	freopen("string.out","w",std.out);
	int n,c=0,e=0;
	string b;
	cin>>n;
		string a;
		cin>>q>>a;
	for(int i=1;i<=n;i++){
		int q;
		for(int j=1;j<=q;j++){
		c+=q;
	}
			b+=a;
		}
	for(int i=1;i<=c/2;i++){
		if(b[i-1]!=b[c-i]){
		}
			e++;
	}
	cout<<e;
	return 0;
}

