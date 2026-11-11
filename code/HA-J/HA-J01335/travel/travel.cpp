#include<bits/stdc++.h>
using namespace std;
int a,b,n,m,p;
string c1,c2;   
char s1[2],s2[2],m1,m2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	for(int i = 1;i <= 2;i++){
		cin>>s1[i];
	}
	cin>>m1;
	cin>>c2;
	for(int i = 1;i <= 2;i++){
		cin>>s2[i];
	}
	cin>>m2;
	if(c1 == c2) cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	if(s1[1] == s2[1] && s1[2] == s2[2]){
		cout<<1;
		a = 1;
	}
	else cout<<0;
	n = m1 - 'A' + 16;
	m = m2 - 'A';
	p = n - m;
	if(a == 1 && ((n <= 2 && m <= 2) || (n >= 3 && m >= 3))){
		cout<<1;
		b = 1;
	}
	else cout<<0;
	if(b == 1 && (p == 1 || p == -1)) cout<<1;
	else cout<<0; 
	return 0;
}
