#include <bits/stdc++.h>
using namespace std;
string a,b;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.our","w",stdout);
	int  n,c,z,w=0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> c;
		cin >> a;
		for(int j=0;j <c;j++){b = b+a;}
	}
	z = b.size();
	for(int e =0;e<z/2;e++){
		if(b[e] !=b[z-(z/2)+e]){
			w++; 
		}
	}
	cout << w;
	return 0;
}
