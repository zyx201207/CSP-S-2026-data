#include<bits\stdc++.h>
using namespace std;

unsigned long long l,shu,cnt;

char a;
string b,bijiao_1,bijiao_2;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>l;
	for(int i=1;i<=l;i++){

	cin>>shu;
	cin>>a;

for(int j=1;j<=shu;j++) b+=a;
	
	}
	
	
	for(int i=0 ; i<b.size()/2 ; i++) bijiao_1+=b[i];
	for(int i=l+1 ; i>(l-b.size()/2)  ; --i) bijiao_2+=b[i];


	for(int i=1 ; i<=bijiao_1.size() ; i++){
		if(bijiao_1[i-1] != bijiao_2[i-1]) cnt++;


	}
	

	cout<<cnt;
	
	return 0;
}
