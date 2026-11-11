#include<bits/stdc++.h>
using namespace std;
int R,X,i,j,n,m;
string Rs,Xs;
bool b=1;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>R>>Rs>>X>>Xs;
	n=(Rs[0]-'0')*10+(Rs[1]-'0');
	m=(Xs[0]-'0')*10+(Xs[1]-'0');
	i=Rs[2]-'A';
	j=Xs[2]-'A';
	if(R==X)cout<<"1";
	else {
		cout<<"0";
		b=0;
	}
	if(n==m)cout<<b;
	else {
		cout<<"0";
		b=0;
	}
	if((i<=2&&j<=2)||(i>2&&j>2))cout<<b;
	else {
		cout<<"0";
		b=0;
	}
	if(i+j-min(i,j)*2==1)cout<<b;
	else {
		cout<<"0";
		b=0;
	}
	return 0;
}

