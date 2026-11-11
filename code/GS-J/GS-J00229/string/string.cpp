#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,i,j,w,x=0;
	cin>>a;
	long long b[a+5];
	char c[a+5];
	string s="";
	for(i=0;i<a;i++){
		cin>>b[i]>>c[i];
		s.append(b[i],c[i]);
	}
	w=s.size()-1;
	for(j=0;j<(w+1)/2;j++){
		if(s[j]!=s[w-j])
			x=x+1;
	}
	cout<<x;
	
	return 0;
}
