#include<bits/stdc++.h>
using namespace std;
int p1,p2,n1,n2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>p1>>s1>>p2>>s2;
	n1=(s1[0]-'0')*10+(s1[1]-'0');
	n2=(s2[0]-'0')*10+(s2[1]-'0');
	int ss1=(s1[2]-'A');
	int ss2=(s2[2]-'A');
	cout<<(p1==p2);
	cout<<(p1==p2&&n1==n2);
	cout<<((p1==p2&&n1==n2)&&((ss1<=2&&ss2<=2)||(ss1>=3&&ss2>=3)));
	cout<<((p1==p2&&n1==n2)&&max(ss1,ss2)-min(ss1,ss2)==1&&max(ss1,ss2)!=3);
} 

