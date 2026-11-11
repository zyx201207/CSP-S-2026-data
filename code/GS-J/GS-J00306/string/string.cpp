#include<bits/stdc++.h>
using namespace std;
string a;
int b,i;
int main(){
	freopen("string.in","w",stdin);
	freopen("string .out","r",stdout);
	cin>>a>>b;
	for (i=0;i<=b;i++){
		if(a[i]==a[b-1]){
			cout<<3;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
   
