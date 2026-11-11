#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,num;
	string c,s=" ";
	cin>>n;
	for(int i=0;i<=n;i++){
		cin>>a>>c;
	}
	for(int j=0;j<=a;j++){
		s=c[j]	;
	
        if(s[0]!=s[j]){
     	    num++;
	}
    cout<<num;
	
	return 0;
}
