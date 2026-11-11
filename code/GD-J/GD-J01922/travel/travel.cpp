#include<bits/stdc++.h>
using namespace std;
long long a,b,c;
int n[5];
string x,r;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>b>>r;
	c=(x[0]-r[0])+(x[1]-r[1]);
	int d=0;
	if(c<=1 and x[1]!=9 and r[0]!=1 and x[1]!=9 and r[0]!=1)  d++;
	if(x[2]-r[2]!=0 and c!=0)  d--;
	else if(x[2]=='C' and r[2]=='D') d--;
	else if(r[2]=='C' and x[2]=='D') d--;
	
	if(a==b)  n[0]=1;
	if(a==b and c==0)  n[1]=1;
	if(a==b and c==0 and x[2]<='C' and r[2]<='C')  n[2]=1;
	else if(a==b and c==0 and x[2]>'C' and r[2]>'C')  n[2]=1;
	if(d>=1 and a==b and c<=1 and x[2]-r[2]<=1 and r[2]-x[2]<=1)  n[3]=1;
	for(int i=0;i<4;i++){
		cout<<n[i];
	}
	return 0;
}
