#include<bits/stdc++.h>
#define N 
using namespace std;
const string L="ABCDF";
string c1,s1,c2,s2;
int n1,n2;
int l1,l2;
bool B1,B2,B3,B4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	
	B1=(c1==c2);
	
	n1=(s1[0]-'0')*10+(s1[1]-'0');
	n2=(s2[0]-'0')*10+(s2[1]-'0');
	B2=B1 && (n1==n2);
	
	l1=L.find(s1[2]);
	l2=L.find(s2[2]);
	B3=B2 && ((l1>2)==(l2>2));
	
	B4=B3 && (abs(l1-l2)<=1);
	
	//cout<<n1<<' '<<n2<<' '<<l1<<' '<<l2;
	
	cout<<B1<<B2<<B3<<B4;
	
	return 0;
}
