#include<bits/stdc++.h>
using namespace std;
string x1,x2,y1,y2,a="",b="";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x1>>x2>>y1>>y2;
	if(x1==y1){
		cout<<"1";
		a=x2[0]+x2[1];
		b=y2[0]+y2[1];
		if(a==b){
			cout<<"1";
			a=x2[2];
			b=y2[2];
			if(x2[2]>='D'&&y2[2]>='D'||x2[2]<='C'&& y2[2]<='C'){
				cout<<"1";	
				if(a>b)
				swap(a,b);
				if(b[0]=='B'&&a[0]=='A'||b[0]=='C'&&a[0]=='B'||b[0]=='F'&&a[0]=='D')
				cout<<"1"<<endl;
				else
				cout<<"0"<<endl;
				
			}else{
				cout<<"00"<<endl;
			}
		}else{
			cout<<"000"<<endl;
		}
	}else{
		cout<<"0000"<<endl;
	}
	return 0;
} 
