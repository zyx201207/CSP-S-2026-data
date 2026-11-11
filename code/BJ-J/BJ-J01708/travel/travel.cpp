#include<bits/stdc++.h>
using namespace std;

string c1,c2,x1,x2;
int h1,h2,l1,l2;

bool f1,f2,f3,f4;

bool side(int x,int y){
	if(x<=2 &&y<=2){
		return true;
	}
	if(x>=3 && y>=3){
		return true;
	}
	return false;
}


int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>x1>>x2;
	h1=  int(c2[0]-'0')*10+int(c2[1]-'0');
	h2=  int(x2[0]-'0')*10+int(x2[1]-'0');
	l1= int(c2[2]-'A'),l2=int(x2[2]-'A');
	//cout<<h1<<" "<<h2<<" "<<l1<<" "<<l2<<endl;
	if(c1!=x1){
		f1=0,f2=0,f3=0,f4=0;
	}else if(h1!=h2){
		f1=1,f2=0,f3=0,f4=0;
	}else if(!side(l1,l2)){
		f1=1,f2=1,f3=0,f4=0;
	}else if(abs(l1-l2)!=1){
		f1=1,f2=1,f3=1,f4=0;
	}else{
		f1=1,f2=1,f3=1,f4=1;
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
