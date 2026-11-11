#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	string c1,s1,c2,s2;
	int q1,q2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
			cout<<1;
			q1=s1[0]*10+s1[1]-528;
			q2=s2[0]*10+s2[1]-528;
			//cout<<endl<<"q1:"<<q1<<endl<<"q2:"<<q2<<endl;
			if(q1==q2){
				cout<<1;
				int o1=s1[2]-64;
				int o2=s2[2]-64;
				//cout<<endl<<"o1:"<<o1<<endl<<"o2:"<<o2<<endl;
				if(o1<=3){
					if(o2<=3)
						cout<<1;
					else
						cout<<"0";
				}else{
					if(o2<=3)
						cout<<"0";
					else
						cout<<1;
				}
			}
			else cout<<"00";
	}
	else{cout<<"0000"; return 0;}
	q1=s1[0]*10+s1[1]-528;
	q2=s2[0]*10+s2[1]-528;
	int o1=s1[2]-64;
	int o2=s2[2]-64;
	if(q1==q2&&c1==c2){
		if(o1<=3){
			if(o2<=3){
				if((o1-o2)==1||(o2-o1)==1)cout<<1;
				else cout<<"0";
			}
				
			else
				cout<<"0";
		}
		else{
			if(o2<=3)
				cout<<"0";
			else{
				if((o1-o2)==1||(o2-o1)==1)cout<<1;
				else cout<<"0";}
		}
	}
	else if(o1==o2){
		if((q1-q2)==1||(q2-q1)==1)
			cout<<1;
		else
			cout<<0;
	}
	else
		cout<<0;
	return 0;
}
