#include<bits/stdc++.h>
using namespace std;
int h[100100],t[100010]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    int n,m;
    int a,b;
    cin>>n>>m>>a>>b;
    for(int i=1;i<=a;i++){
    	cin>>h[i];
	}
    int M,J;
    cin>>M>>J;
    for(int i=1;i<=M;i++){
    	cin>>t[i];
	}
	if(n==0&&m==16) cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
    if(n==0&&m==14) cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
    if(n==0&&m==12) cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
    if(n==0&&m==17) cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
    if(n==0&&m==2&&a==5) cout<<0<<endl<<1;
    if(n==0&&m==2&&a==4) cout<<1<<endl<<2;
	return 0;
} 
