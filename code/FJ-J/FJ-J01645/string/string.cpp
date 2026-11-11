#include <bits/stdc++.h>
using namespace std;
long long int n,l,r,a,k,s;
string dzh;
char str;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>str;
		for(int j=0;j<a;j++){
			dzh[k]=str;
			k++;
		}
	}
	r=k-1;
	while(l<=r){
		if(dzh[l]!=dzh[r]) {
			dzh[r]=dzh[l];
			s++;
		}
		l++;
		r--;
	}
	cout<<s;
	return 0;
}
