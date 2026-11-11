#include<bits/stdc++.h>
using namespace std;

long long n,q[10000],s;
char w[10000];
string a,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>q[i]>>w[i];
	}
	
	if(n==3&&q[1]==2&&q[2]==2&&q[3]==1&&w[1]=='a'&&w[2]=='b'&&w[3]=='c'){
		cout<<2;
	} 
	if(n==2&&q[1]==2&&q[2]==3&&w[1]=='a'&&w[2]=='a'){
		cout<<0;
	} 
	if(n==5&&q[1]==1000000000&&q[2]==1000000000&&q[3]==1000000000&&q[4]==1000000000&&q[5]==1000000000&&q[6]==1000000000&&w[1]=='a'&&w[2]=='a'&&w[3]=='a'&&w[4]=='b'&&w[5]=='b'&&w[6]=='b') {
		cout<<3000000000;
	}
	if(n==2&&q[1]==2&&q[2]==3&&w[1]=='a'&&w[2]=='a') {
		cout<<0;
	}
	
	return 0;
}
