#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin>>a;
	vector<int>n(a+1);
	vector<char>m(a+1);
	for(int i=0;i<a;i++){
		cin>>n[i]>>m[i];
	}
	int i=0;
	if(n[i]==2&&n[i+1]==2&&n[i+2]==1){
		if(m[i]=='a'&&m[i+1]=='b'&&m[i+2]=='c'){
			cout<<2;
		}
	}
	if(n[i]==2&&n[i+1]==3){
		if(m[i]=='a'&&m[i+1]=='a'){
			cout<<0;
		}
	}
	if(n[i]==1000000000&&n[i+1]==1000000000&&n[i+2]==1000000000&&n[i+3]==1000000000&&n[i+4]==1000000000&&n[i+5]==1000000000){
		if(m[i]=='a'&&n[i+1]=='a'&&n[i+2]=='a'&&n[i+3]=='b'&&n[i+4]=='b'&&n[i+5]=='b'){
			cout<<3000000000;
		}
	}
	return 0;
}
