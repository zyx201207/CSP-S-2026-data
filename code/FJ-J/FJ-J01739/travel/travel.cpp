#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long 
string a,b;
char a1,b1;
int a2,b2,ca,cb;
bool f1,f2,f3,f4;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>a>>cb>>b;
	
	for(int i=0;i<=a.size()-1;i++){
		if(a[i]>='A'&&a[i]<='F') {
			a1=a[i];
			b1=b[i];
		}
		else{
			a2=a2*10+(a[i]-'0');
			b2=b2*10+(b[i]-'0');
		}
	}
	if(ca!=cb){
		cout<<0<<0<<0<<0;
		return 0;
	}else {
		f1=1;//
		if(a2==b2){
			f2=1;
		}//
		bool q=0,w=0;
		if(a1=='A'||a1=='B'||a1=='C') q=0;
		else q=1;
		if(b1=='A'||b1=='B'||b1=='C') w=0;
		else w=1;
		if(q==w&&f2==1) f3=1;//
		if((a1=='D'&&b1=='C')||(a1=='C'||a2=='D')) f4=0;
		else if(a1!='F'&&b1!='F'){
			if(a1==b1&&abs(a2-b2)==1) f4=1;
			else if(a2==b2&&abs(a1-b1)==1) f4=1;
		}
		else if(a1=='F'&&b1=='F'){
			if(abs(a2-b2)==1) f4=1;
		}
		else if((a1=='F'&&b1=='D')||(a1=='D'&&b2=='F')){
			if(a2==b2) f4=1;
		}
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
} 
