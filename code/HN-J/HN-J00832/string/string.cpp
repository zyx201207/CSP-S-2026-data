#include<bits/stdc++.h>
using namespace std;
int n,a,dsa;
long long l;
string asd,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a>>b;
		l+=a;
		for (int j=1;j<=a;j++){
			asd+=b; 
		}
	}
	for (int i=0;i<l/2;i++){
		if (asd[i]!=asd[l-i-1]){
			dsa++;
		}
	}
	cout<<dsa;
	return 0;
}
