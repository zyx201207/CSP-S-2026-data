#include<bits/stdc++.h>
using namespace std;
string n1,n2,m1,m2,c,d;
int n,m,a,b;
int main(){
	cin>>n1>>n2>>m1>>m2;
	a=int(n2[2]);
	b=int(m2[2]);
	c=n2.substr(0,2);
	d=m2.substr(0,2);
	if(n1==m1)cout<<1;
	else cout<<"0";
	if(c==d&&n1==m1)cout<<1;
	else cout<<"0";
	if(c==d&&n1==m1&&((a>67.5&&b>97.5)||(a<67.5&&b<67.5)))cout<<1;
	else cout<<"0";
	if(c==d&&n1==m1&&((a>67.5&&b>97.5)||(a<67.5&&b<67.5))&&(a-b==1)||(b-a==1))cout<<1;
	else cout<<"0";
	return 0;
}
