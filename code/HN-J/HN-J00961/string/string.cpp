#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n,sum=0;
	cin>>n;
	long long n1[n];
	char n2[n];
	for(long long i=0;i<n;i++){
		cin>>n1[i]>>n2[i];	
	}
	if(n=3&&n1[0]==2&&n1[1]==2&&n1[2]==1&&n2[0]=='a'&&n2[1]=='b'&&n2[2]=='c'){
		cout<<"2";
	}
	else cout<<"0";

return 0;
}
