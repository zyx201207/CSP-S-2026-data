#include<bits/stdc++.h> 
using namespace std;
long long a,b,c,d,e,n,m,s;
string A,B,C,D;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>A>>B>>C>>D;
	if(A==C)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(B[1]==D[1]&&B[0]==D[0])cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	b=B[2]-64;
	d=D[2]-64;
	if(b<=3)a=1;
	else a=2;
	if(d<=3)c=1;
	else c=2;
	if(a==c)cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(b-d)==1)cout<<1;
	else cout<<0;
	return 0;
}
