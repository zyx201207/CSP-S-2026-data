#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string d="";
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin >> a >> b;
		for(int j=1;j<=a;j++){
			d+=b;
		}
	}long long f=0;
	for(int i=0;i<=d.size()/2;i++){
		if(d[i]!=d[d.size()-1-i]){
			f++;
		}
	}cout << f;
	return 0;
}
