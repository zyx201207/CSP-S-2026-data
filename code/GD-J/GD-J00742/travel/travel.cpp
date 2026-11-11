#include<iostream>
#include<cmath>
#define F(i,x,y) for(int i=x;i<=y;i++)
#define F2(i,x,y) for(int i=x;i>=y;i--)
#define f(x,y) for(auto x:y)
#define lt(x) x&-x
#define d2(l,r) (l+r>>1)
#define ls(i) i<<1
#define rs(i) i<<1|1
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<endl;
		exit(0);
	}if(!(s1[0]==s2[0]&&s1[1]==s2[1])){
		cout<<"1000"<<endl; 
		exit(0);
	}if(!(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'||s1[2]>='D'&&s1[2]<='E'&&s2[2]>='D'&&s2[2]<='E')){
		cout<<"1100"<<endl;
		exit(0);
	}if(!(abs(s1[2]-s2[2])==1)){
		cout<<"1110"<<endl;
		exit(0);
	}
	cout<<"1111";
	return 0;
} 
