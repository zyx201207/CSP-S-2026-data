#include <bits/stdc++.h>
using namespace std;
long long b[200000];
char c[200000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin>>a;
	for(int i=0;i<a;i++) cin>>b[i]>>c[i];
	string a1="",a2="";
	for(int i=0;i<a;i++) 
		for (int i1=0;i1<b[i];i1++){
		    a1=a1+c[i];
			a2=c[i]+a2;}
	long long q;
	q=a1.length();
	int d=0;
	for(int i=0;i<q;i++) if(a1[i]!=a2[i]) d++;
	cout<<d/2;
	return 0;
}