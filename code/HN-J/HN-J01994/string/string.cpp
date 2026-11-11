#include <bits/stdc++.h>
using namespace std;
string q;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
int n,a,b,c;
string s;
c=0;
cin >>n;
for (int i=1;i<=n;i++){
	cin>>a;
	cin >>s;
	b+=a;
	for (int j=1;j<=a;j++){
		q+=s;		
	}
}
for (int i=1;i<=b/2;i++){
	if(q[i-1]!=q[b-i])
	c++;
	
}

cout <<c;





return 0;
} 
