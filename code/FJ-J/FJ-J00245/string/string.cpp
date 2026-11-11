#include<bits/stdc++.h>
using namespace std;
int n;
int d;
int f;
vector<char> a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int b;
		cin>>b;
		d+=b;
		char c;
		cin>>c;
		for(int j=1;j<=b;j++){
			a.push_back(c);
		}
	}
	for(int i=0,j=d-1;i!=j;i++,j--){
		if(a[i]!=a[j]){
			f++;
		}
	}
	cout<<f;
	return 0;
}


