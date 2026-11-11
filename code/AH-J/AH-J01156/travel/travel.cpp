#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,a1,b,b1;int f1,f2,f3,f4;
	char c1,c2;
	cin>>a>>a1>>c1>>b>>b1>>c2;
	(a==b)?f1=1:f1=0;
	(a1==b1&&f1)?f2=1:f2=0;
	(((c1>='D'&&c2>='D')||(c1>='A'&&c1<='C'&&c2>='A'&&c2<='C'))&&f2)?f3=1:f3=0;
	((abs(c1-c2)==1)&&f3)?f4=1:f4=0;
	cout<<f1<<f2<<f3<<f4;
	}

