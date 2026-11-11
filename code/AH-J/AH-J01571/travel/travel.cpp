#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;

bool check1(){
	int a=::b[2]-'A',b=::d[2]-'A';
	if(a<3 && b<3 || a>2 && b>2){
		return 1;
	} else {
		return 0;
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	bool f1=a==c;
	bool f2=f1 && b[0]==d[0] && b[1]==d[1];
	bool f3=f2 && check1();
	bool f4=f3 && (b[2]-d[2]==1 || b[2]-d[2]==-1);
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
