#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,j=1;
	cin>>a;
	long long s[a];
	string y[a];
	for(int p=0;p<a;p++){
		cin>>s[p]>>y[p];
	}
	for(int p=0;p<a;p++){
		if(y[p]==y[p+1]) j++;
		
	}
	if(a==j) cout<<"0";
	return 0;
}
