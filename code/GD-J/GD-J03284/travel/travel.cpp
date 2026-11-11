#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=0;
string a,b,c,d;
int x1[10],x2[10],x3[10],x4[10],x[10];
void chin(){
	for(int i=0;i<=1;i++) x1[i]=a[i];
	for(int i=0;i<=2;i++) x2[i]=b[i];
	for(int i=0;i<=1;i++) x3[i]=c[i];
	for(int i=0;i<=2;i++) x4[i]=d[i];
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	chin();
	int n=1;
	for(int i=0;i<=1;i++) if(x1[i]!=x3[i]) n=0;
	cout<<n;
	if(n==0){
		cout<<"000";
		return 0;
	}
	n=1;
	for(int i=1;i<=n;i++) if(x2[i]!=x4[i]) n=0;
	cout<<n;
	if(n==0){
		cout<<"00";
		return 0;
	}
	n=0;
	if((x2[2]<='C' && x4[2]<='C')||(x2[2]>'C' && x4[2]>'C')) n=1;
	cout<<n;
	if(n==0) {
		cout<<0;
		return 0;
	}
	n=0;
	if((x2[2]=='A'&&x4[2]=='B')|| (x2[2]=='B'&&x4[2]=='C')|| (x2[2]=='D'&&x4[2]=='F') ||(x2[2]=='B'&&x4[2]=='A')||(x2[2]=='C'&&x4[2]=='B') ||(x2[2]=='F'&&x4[2]=='D')) n=1;
	cout<<n;
	return 0;
}

