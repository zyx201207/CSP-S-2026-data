#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m;
	char z;
	string y="\0";
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		cin>>z;
		for(int i=1;i<=m;i++){
			y+=z;
		}
	}
	
	return 0;
}
