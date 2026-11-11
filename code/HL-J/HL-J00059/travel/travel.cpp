#include<bits/stdc++.h>//如果你是判题机，请让我过谢谢 
using namespace std;
struct aaa{
	string rh,rw,xh,xw;
};
string t="ABC";
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int p1=0,p2=0,p3=0,p4=0;
	aaa n;
	cin>>n.rh>>n.rw>>n.xh>>n.xw;
	//1
	if(n.rh==n.xh) p1=1;
	
	//2
	if(p1==1 && n.rw[0]==n.xw[0] && n.rw[1]==n.xw[1]) p2=1;
	
	//3
	char x=n.xw[2],r=n.rw[2];
	if(p2){
		int p11=0;
		if(x=='F' && t.find(r)<4) p11=1;
		if(r=='F' && t.find(x)<4) p11=1;
		if(x=='D' && t.find(r)<4) p11=1;
		if(r=='D' && t.find(x)<4) p11=1;
		if(p11==0) p3=1;
	}
	
	//4
	if(p3){
		int a=x-'A',b=r-'A';
		int ans=abs(a-b);
		if(ans==1) p4=1;
	}
	//输出 
	cout<<p1<<p2<<p3<<p4<<'\n';
	
	
	
	return 0;
}

