#include <bits/stdc++.h>
using namespace std;
char a2[300000];
int a3[300000];
int z(int x1,char q,string a,int b){
		int w1=0;
		for(int i1=0;i1<x1;i1++) if(a[i1]==q) w1=1;
		if (w1==1) {
			int a1=a.find(q);
			int a4=a.find(q,a1+1);
			for(int x=a1;x<a4;x++) {
			string a1="";
			a1=a1+a[x];
			a[x]='0';
			}}
		for(int i1=0;i1<=x1;i1++)
		for(int i2=0;i2<b;i2++)
			if (a[i1]==a2[i2]) a3[i2]=a3[i2]+1;	
}
main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,b=0;
	cin>>n>>m;
	string a;
	int i;
	char q;
	for ( i=0;i<n;i++) {
		cin>>q;
		a=a+q;
		int w=0;
		for(int i1=0;i1<=b;i1++) if(a2[i1]==q) w=1;
		if(w==0){
			a2[b]=q;
			b++;}}
	z(i,q,a,m);
	for(int i=0;i<b-1;i++) cout<<a3[i]<<" ";
	cout<<a3[b];	
}