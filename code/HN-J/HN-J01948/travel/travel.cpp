#include<bits/stdc++.h>
using namespace std;
int a,c;
char b[5],d[5];

int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
	}else cout<<"0";
	int q=b[0]+b[1],w=d[0]+d[1];
	int e=b[2],r=d[2];
	if(a==c and q==w){
		cout<<"1";
	}else cout<<"0";
	if(a==c and q==w and e<='C'+'0' and r<='C'+'0'||a==c and q==w and e>='D'+'0' and r>='D'+'0'){
		if(e=='C' and r!='D'||e=='D' and r!='C'){
		cout<<"1";	
		}else{
			cout<<'0';
		}
		
	}else{
	cout<<"0";
	}
	if(q==w and e+'1'==r|| q==w and e-'1'==r ||q==w and e=='D'and r=='F'||q==w and e=='F'and r=='D'){
		cout<<"1";
	}else{
	cout<<"0";
	}
	
	
	return 0;
}
